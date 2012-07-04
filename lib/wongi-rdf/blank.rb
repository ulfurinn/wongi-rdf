module Wongi
  module RDF
    class Blank < Node

      attr_reader :id, :document

      def initialize id, document = nil
        @id = id
        @document = document
      end

      def == other
        super && id == other.id
      end

      def to_s
        "_:#{id}"
      end

      def import document
        if document == self.document
          self
        else
          self.class.new id, document
        end
      end
      
    end
  end
end
