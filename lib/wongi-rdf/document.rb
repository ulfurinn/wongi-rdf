module Wongi
  module RDF
    class Document

      attr_reader :statements
      attr_reader :namespaces
      attr_reader :base

      def initialize
        @statements = []
        @namespaces = {} 
      end

      def empty?
        statements.empty? && namespaces.empty?
      end

      def base= b
        unless base.nil? || base == b
          raise BaseException.new( "Cannot replace document base #{base} with #{b}" )
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
            raise "Unknown prefix #{parsed[0]} while expanding qname #{uri}"
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

      def register prefix, full
        namespaces[prefix] = full
      end

      def lookup prefix
        namespaces[prefix]
      end

      def << statement
        statements << statement
      end

    end 
  end
end
