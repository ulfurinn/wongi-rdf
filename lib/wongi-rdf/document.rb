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
        @used_blanks = { }
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

      def blank id = nil
        if id.nil? 
          while has_blank? "blank#{@blank_counter}"
            @blank_counter += 1
          end
          id = "blank#{@blank_counter}"
        end
        Blank.new id, self
      end

      def register prefix, full
        namespaces[prefix] = full
      end

      def lookup prefix
        namespaces[prefix]
      end

      def << statement
        [:subject, :predicate, :object].each do |node_name|
          node = statement.send node_name
          if node.kind_of? Blank
            @used_blanks[node.id] = true
          end
        end
        statements << statement
      end

      def has_blank? id
        @used_blanks[id]
      end

    end 
  end
end
