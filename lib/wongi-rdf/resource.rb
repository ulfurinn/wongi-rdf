module Wongi
  module RDF
    class Resource < Node

      attr_reader :uri, :document

      QNAME = /^([a-zA-Z][a-zA-Z0-9_-]*):([a-zA-Z][a-zA-Z0-9_-]*)$/

      def self.parse_qname string
        match = (string.match QNAME)
        if match
          [match[1], match[2]]
        end
      end

      def initialize uri, document = nil
        @uri = uri
        @document = document        
      end

      def == other
        # => comparing URIs directly doesn't work for some reason, investigate?..
        super && uri.to_s == other.uri.to_s
      end

      def to_s
        uri.to_s
      end

      def import document
        if document == self.document
          self
        else
          self.class.new uri, document
        end
      end

    end
  end
end
