module Wongi
  module RDF
    class Document

      include Wongi::RDF::DocumentSupport
      include Wongi::RDF::Searchable

      def initialize
        @statements = [ ]
        @namespaces = { } 
        @blank_counter = 1
        @ns_counter = 0
        @used_blanks = { }
      end


      def << statement
        case statement
        when Array
          self << self.statement( *statement )
        when Statement
          [:subject, :predicate, :object].each do |node_name|
            node = statement.send node_name
            if node.kind_of? Blank
              @used_blanks[node.id] = true
            end
          end
          statements << statement
        end
      end

      alias_method :assert, :<<


    end 
  end
end
