module Wongi
  module RDF

    module DocumentSupport

      attr_reader :statements
      attr_reader :namespaces
      attr_reader :base

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

      # Attempts to create a resource from anything URI-like.
      # @param [Node, URI::Generic, String, #to_uri] uri
      # @raise if the argument cannot be interpreted as a URI
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

      # Attempts to create a Resource from a QName.
      # The namespace must be known to the document.
      # @param [String] qname the string to expand
      # @return [Resource, NilClass] the created Resource
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
        namespaces[real_prefix] = if full.is_a? URI::Generic
          full
        else
          URI.parse full
        end
        real_prefix
      end

      def lookup_namespace prefix
        namespaces[prefix]
      end

      # Constructs a statement.
      def statement s, p, o
        Statement.new s, p, o, self
      end

      # Constructs a statement and adds it to the graph.
      def statement! s, p, o
        self << Statement.new( s, p, o, self )
      end

      def has_blank? id
        @used_blanks.has_key? id
      end

      private

      def expand_split ns, local
        ns = lookup_namespace ns
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
