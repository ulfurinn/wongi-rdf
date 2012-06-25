require 'spec_helper'
require 'rdf_test_helper'
require 'rdf_test_inputs'

require 'wongi-rdf/parser'
require 'wongi-rdf/document'
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
  end

  it 'should parse prefixes' do
    test_document :prefixes
    @document.namespaces.should have(1).item
    @document.namespaces.should have_key("ns")
    @document.namespaces["ns"].should be_a_kind_of( URI )
    @document.namespaces["ns"].to_s.should == "http://test/ns/"
  end

end
