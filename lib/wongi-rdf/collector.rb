module Wongi
  module RDF
    class Collector

      attr_reader :document

      def initialize document
        @document = document
        @mapping = { }
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
