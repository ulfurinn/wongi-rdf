module Wongi::RDF
  module Searchable

    def find s, p, o
      statements.find { |st|
        ( s.nil? || s == st.subject ) && ( p.nil? || p == st.predicate ) && ( o.nil? || o == st.object )
      }
    end

    def select s, p, o
      statements.select { |st|
        ( s.nil? || s == st.subject ) && ( p.nil? || p == st.predicate ) && ( o.nil? || o == st.object )
      }
    end

  end
end
