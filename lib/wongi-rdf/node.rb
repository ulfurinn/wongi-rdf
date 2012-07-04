module Wongi
  module RDF
    class Node

      def == other
        other.class == self.class && other.document == self.document
      end

    end
  end
end
