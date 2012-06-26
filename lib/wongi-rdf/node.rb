module Wongi
  module RDF
    class Node

      def == other
        other.class == self.class
      end

    end
  end
end
