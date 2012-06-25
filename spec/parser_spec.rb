require 'spec_helper'
require 'rdf_test_helper'
require 'rdf_test_inputs'

require 'wongi-rdf/parser'
require 'wongi-rdf/document'
require 'wongi-rdf/resource'
require 'wongi-rdf/statement'
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
    @document.namespaces.should have(1).item
    @document.namespaces.should have_key("ns")
    @document.namespaces["ns"].should be_a_kind_of( URI )
    @document.namespaces["ns"].to_s.should == "http://test/ns/"
  end

  it 'should parse prefixes into an existing document' do
    document = Wongi::RDF::Document.new
    document.should be_empty
    test_document :prefixes, document
    @document.should == document
    @document.namespaces.should have(1).item
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
    lambda { test_document :base, document }.should_not raise_error( Wongi::RDF::BaseException )
    lambda { test_document :base1, document }.should raise_error( Wongi::RDF::BaseException )
  end

  it 'should parse n3 statements' do
    test_document :n3
    @document.statements.should have(1).item

    statement = @document.statements.first
    statement.subject.uri.to_s.should == "http://test/node1"
    statement.predicate.uri.to_s.should == "http://test/node2"
    statement.object.uri.to_s.should == "http://test/node3"
  end

  it 'should parse simple statements with qnames' do
    test_document :qnames
    @document.statements.should have(1).item

    statement = @document.statements.first
    statement.subject.uri.to_s.should == "http://test/node1"
    statement.predicate.uri.to_s.should == "http://test/node2"
    statement.object.uri.to_s.should == "http://test/node3"
  end

end
