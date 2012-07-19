require 'spec_helper'
require 'rdf_test_helper'
require 'rdf_test_inputs'

require 'wongi-rdf/parser'
require 'wongi-rdf/exceptions'
require 'wongi-rdf/searchable'
require 'wongi-rdf/document_support'
require 'wongi-rdf/document'
require 'wongi-rdf/node'
require 'wongi-rdf/blank'
require 'wongi-rdf/resource'
require 'wongi-rdf/statement'
require 'wongi-rdf/collector'
require 'wongi_turtle'

describe "the RDF parser" do

  include RdfTestHelper
  include RdfTestInputs

  before :each do
    @parser = Wongi::RDF::Parser.new
  end

  it "should parse empty documents" do
    test_document :empty
    @document.should be_a_kind_of( Wongi::RDF::Document )
    @document.should be_empty
    @document.base.should be_nil
  end

  it 'should parse prefixes' do
    test_document :prefixes
    @document.should have(1).namespaces
    @document.namespaces.should have_key("ns")
    @document.namespaces["ns"].should be_a_kind_of( URI )
    @document.namespaces["ns"].to_s.should == "http://test/ns/"
  end

  it 'should parse prefixes into an existing document' do
    document = Wongi::RDF::Document.new
    document.should be_empty
    test_document :prefixes, document
    @document.should == document
    @document.should have(1).namespaces
    @document.namespaces.should have_key("ns")
    @document.namespaces["ns"].should be_a_kind_of( URI )
    @document.namespaces["ns"].to_s.should == "http://test/ns/"
  end

  it 'should parse document base' do
    test_document :base
    @document.should be_empty
    @document.base.should be_a_kind_of( URI )
    @document.base.to_s.should == "http://test/base/"
  end

  it 'should not replace a document\'s base' do
    document = Wongi::RDF::Document.new
    document.base = URI.parse( 'http://test/base/' )
    lambda { test_document :base, document }.should_not raise_error( Wongi::RDF::BaseExists )
    lambda { test_document :base1, document }.should raise_error( Wongi::RDF::BaseExists )
  end

  it 'should parse n3 statements' do
    test_document :n3
    @document.should have(1).statements

    statement = @document.statements.first
    statement.subject.uri.to_s.should == "http://test/node1"
    statement.predicate.uri.to_s.should == "http://test/node2"
    statement.object.uri.to_s.should == "http://test/node3"
  end

  it 'should parse simple statements with qnames' do
    test_document :qnames
    @document.should have(1).statements

    statement = @document.statements.first
    statement.subject.uri.to_s.should == "http://test/node1"
    statement.predicate.uri.to_s.should == "http://test/node2"
    statement.object.uri.to_s.should == "http://test/node3"
  end

  it 'should parse the rdf:type shorthand' do
    test_document :a
    @document.statements.should include( Wongi::RDF::Statement.new "test:node1", "rdf:type", "test:node2", @document )
  end

  it 'should parse object lists' do
    test_document :object_list
    @document.should have(3).statements
    @document.statements.should include( Wongi::RDF::Statement.new "test:node1", "test:node2", "test:node31", @document )
    @document.statements.should include( Wongi::RDF::Statement.new "test:node1", "test:node2", "test:node32", @document )
    @document.statements.should include( Wongi::RDF::Statement.new "test:node1", "test:node2", "test:node33", @document )
  end

  it 'should parse predicate lists' do
    test_document :predicate_list
    @document.should have(2).statements
    @document.statements.should include( Wongi::RDF::Statement.new "test:node1", "test:node21", "test:node31", @document )
    @document.statements.should include( Wongi::RDF::Statement.new "test:node1", "test:node22", "test:node32", @document )
  end

  it 'should parse mixed object and predicate lists' do
    test_document :object_and_predicate_list
    @document.should have(3).statements
    @document.statements.should include( Wongi::RDF::Statement.new "test:node1", "test:node21", "test:node31", @document )
    @document.statements.should include( Wongi::RDF::Statement.new "test:node1", "test:node22", "test:node321", @document )
    @document.statements.should include( Wongi::RDF::Statement.new "test:node1", "test:node22", "test:node322", @document )
  end

  context 'when parsing collections' do

    it 'should parse empty collections' do
      test_document :empty_collection

      @document.should have(1).statements
      @document.statements.first.object.should == @document.expand( "rdf:nil" )
    end

    it 'should parse one-element collections' do
      test_document :one_element_collection

      @document.should have(3).statements
      first = @document.find( @document.expand("test:node1"), @document.expand("test:node2"), :_ )
      first.should_not be_nil
      blank = first.object
      @document.should contain( blank, @document.expand("rdf:first"), @document.expand("test:node31") )
      @document.should contain( blank, @document.expand("rdf:rest"), @document.expand("rdf:nil") )
    end

    it 'should parse two-element collections' do
      test_document :two_element_collection

      @document.should have(5).statements

      collection = @document.find( @document.expand("test:node1"), @document.expand("test:node2"), :_ ).object
      @document.should contain( collection, @document.expand("rdf:first"), @document.expand("test:node31") )

      second = @document.find( collection, @document.expand("rdf:rest"), :_ ).object

      @document.should contain( second, @document.expand("rdf:first"), @document.expand("test:node32") )
      @document.should contain( second, @document.expand("rdf:rest"), @document.expand("rdf:nil") )

    end

  end

  it 'should parse blank nodes' do
    test_document :blanks
    @document.should have(1).statements
    statement = @document.statements.first
    statement.subject.should == @document.resource( "test:node1" )
    statement.predicate.should == @document.resource( "test:node2" )
    statement.object.should == @document.blank( "blank1" )
  end

  it 'should parse shortcut blanks' do
    test_document :shortcut
    @document.should have(3).statements

    parent_statement = @document.statements.find { |st| st.subject.kind_of?( Wongi::RDF::Resource ) && st.subject.uri == URI.parse( "http://test/node1" ) }
    parent_statement.should_not be_nil

    blank = parent_statement.object
    blank.should be_a_kind_of( Wongi::RDF::Blank )

    child_statements = @document.statements.select { |st| st.subject == blank }
    child_statements.should have(2).items

  end

  it 'should remap blanks from another document' do
    document = Wongi::RDF::Document.new
    test_document :blanks, document
    test_document :blanks, document

    @document.should have(2).statements

    statement = @document.statements.first
    statement.subject.should == @document.resource( "test:node1" )
    statement.predicate.should == @document.resource( "test:node2" )
    statement.object.should == @document.blank( "blank1" )

    remapped_statement = @document.statements.last
    remapped_statement.subject.should == @document.resource( "test:node1" )
    remapped_statement.predicate.should == @document.resource( "test:node2" )
    remapped_statement.object.should_not == @document.blank( "blank1" )
  end

end
