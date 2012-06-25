module Wongi
  module RDF
    class Document

      attr_reader :statements
      attr_reader :namespaces
      attr_reader :base

      def initialize
        @statements = []
        @namespaces = {} 
      end

      def empty?
        statements.empty? && namespaces.empty?
      end

      def base= b
        unless base.nil? || base == b
          raise BaseException.new( "Cannot replace document base #{base} with #{b}" )
        end
        @base = b
      end

    end 
  end
end
