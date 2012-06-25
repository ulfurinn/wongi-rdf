module Wongi
  module RDF
    class Resource

      attr_reader :uri, :document

      def initialize uri, document = nil
        @uri = uri
        @document = document        
      end

    end
  end
end
