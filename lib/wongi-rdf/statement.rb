module Wongi
  module RDF
    class Statement < Struct.new( :subject, :predicate, :object )

      attr_reader :document

      def initialize s, p, o, document = nil
        super( ensure_resource(s, document), ensure_resource(p, document), ensure_resource(o, document) )
      end

      def == other
        subject == other.subject && predicate == other.predicate && object == other.object
      end

      def to_s
        "<#{subject} #{predicate} #{object}>"
      end

      private

      def ensure_resource r, document
        if r.kind_of? Resource
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
