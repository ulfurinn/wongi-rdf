module Wongi
  module RDF

    # A single fact.
    class Statement < Struct.new( :subject, :predicate, :object )

      attr_reader :document

      def initialize s, p, o, document = nil
        super( ensure_node(s, document), ensure_node(p, document), ensure_node(o, document) )
      end

      def == other
        subject == other.subject && predicate == other.predicate && object == other.object
      end

      def to_s
        "<#{subject} #{predicate} #{object}>"
      end

      private

      def ensure_node r, document
        if r.kind_of? Node
          r
        elsif document
          document.resource r
        else
          raise "Cannot convert #{r.inspect} into a resource without a document"
        end
      end
    end
    
  end
  
end
