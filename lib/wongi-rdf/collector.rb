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
        existing = document.lookup prefix
        if existing && existing != full
          @ns_alias[prefix] = document.register( nil, full )
        else
          document.register prefix, full
        end
      end

      def lookup prefix
        if @ns_alias.has_key? prefix
          document.lookup @ns_alias[prefix]
        else
          document.lookup prefix
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
