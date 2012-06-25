module Wongi
  module RDF
    class Statement < Struct.new( :subject, :predicate, :object )
      def initialize s, p, o
        super
      end
    end
    
  end
  
end
