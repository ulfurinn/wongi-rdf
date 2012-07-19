module Wongi::RDF
  module Searchable

    def find s, p, o
      statements.find { |st|
        ( s == :_ || s == st.subject ) && ( p == :_ || p == st.predicate ) && ( o == :_ || o == st.object )
      }
    end

    def contains? s, p, o
      !find(s, p, o).nil?
    end

    def select s, p, o
      statements.select { |st|
        ( s == :_ || s == st.subject ) && ( p == :_ || p == st.predicate ) && ( o == :_ || o == st.object )
      }
    end

  end
end
