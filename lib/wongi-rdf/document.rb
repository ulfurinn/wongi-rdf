module Wongi
  module RDF
    class Document

      include Wongi::RDF::Searchable

      attr_reader :statements
      attr_reader :namespaces
      attr_reader :base

      def initialize
        @statements = [ ]
        @namespaces = { } 
        @blank_counter = 1
        @ns_counter = 0
        @used_blanks = { }
      end

      def common!
        register "rdf", URI.parse( "http://www.w3.org/1999/02/22-rdf-syntax-ns#" )
      end

      def empty?
        statements.empty? && namespaces.empty?
      end

      def base= b
        unless base.nil? || base == b
          raise BaseExists.new( "Cannot replace document base #{base} with #{b}" )
        end
        @base = b
      end

      def resource uri
        if uri.kind_of?( Wongi::RDF::Node )
          return uri.import( self )
        end
        real_uri = if uri.kind_of? URI::Generic
          uri
        elsif uri.respond_to? :to_uri
          uri.to_uri
        elsif parsed = Resource.parse_qname( uri )
          expand_split *parsed
        else
          begin
            URI.parse uri
          rescue
            nil
          end
        end
        raise "Cannot create an RDF resource from #{uri}" unless real_uri
        Resource.new real_uri, self
      end

      def expand qname
        if parsed = Resource.parse_qname( qname )
          Resource.new( expand_split( *parsed ), self )
        end
      end

      def blank id = nil
        if id.nil? 
          while has_blank? "blank#{@blank_counter}"
            @blank_counter += 1
          end
          id = "blank#{@blank_counter}"
        end
        Blank.new id, self
      end

      def new_ns
        ns = "ns#{@ns_counter}"
        @ns_counter += 1
        ns
      end

      def register prefix, full
        real_prefix = prefix || new_ns
        namespaces[real_prefix] = if full.is_a? URI::Generic then full else URI.parse full end
        real_prefix
      end

      def lookup prefix
        namespaces[prefix]
      end

      def << statement
        case statement
        when Array
          self << self.statement( *statement )
        when Statement
          [:subject, :predicate, :object].each do |node_name|
            node = statement.send node_name
            if node.kind_of? Blank
              @used_blanks[node.id] = true
            end
          end
          statements << statement
        end
      end

      alias_method :assert, :<<

      def statement s, p, o
        Statement.new s, p, o, self
      end

      def statement! s, p, o
        self << Statement.new( s, p, o, self )
      end

      def has_blank? id
        @used_blanks[id]
      end

      private

      def expand_split ns, local
        ns = lookup ns
        if ns.nil?
          raise UnknownQNameNamespace.new( ns, local )
        end
        if ns.to_s[-1] == "#"   # => concatenating URIs doesn't work when it ends with a hash...
          URI.parse( ns.to_s + local )
        else
          ns + local
        end
      end

    end 
  end
end
