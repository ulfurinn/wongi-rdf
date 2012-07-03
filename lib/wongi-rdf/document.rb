module Wongi
  module RDF
    class Document

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
        real_uri = if uri.kind_of? URI::Generic
          uri
        elsif uri.respond_to? :to_uri
          uri.to_uri
        elsif parsed = Resource.parse_qname( uri ) and parsed.length == 2
          ns = lookup parsed[0]
          unless ns
            raise UnknownQNameNamespace.new( *parsed )
          end
          ns + parsed[1]
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
        namespaces[real_prefix] = full
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

    end 
  end
end
