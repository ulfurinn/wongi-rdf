module Wongi
  module RDF
    class Collector

      attr_reader :document

      def initialize document
        @document = document
        @mapping = { }
        @ns_alias = { }
      end

      def register prefix, full
        if @ns_alias.has_key? prefix
          @ns_alias[prefix]
        else
          existing = document.lookup_namespace prefix
          if existing && existing != full
            @ns_alias[prefix] = document.register nil, full
          elsif not existing
            @ns_alias[prefix] = document.register prefix, full
          end
          @ns_alias[prefix]
        end
      end

      def lookup prefix
        if @ns_alias.has_key? prefix
          document.lookup_namespace @ns_alias[prefix]
        else
          document.lookup_namespace prefix
        end
      end

      def import_blank id
        if ! @mapping.has_key? id
          @mapping[id] = if document.has_blank? id
            document.blank
          else
            document.blank id
          end
        end
        @mapping[id]
      end

    end
  end
end
