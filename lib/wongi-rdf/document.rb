module Wongi
  module RDF
    class Document

      attr_reader :statements
      attr_reader :namespaces
      attr_accessor :base

      def initialize
        @statements = []
        @namespaces = {} 
      end

      def empty?
        statements.empty? && namespaces.empty?
      end

    end 
  end
end
