require 'spec_helper'
require 'wongi-rdf/exceptions'
require 'wongi-rdf/node'
require 'wongi-rdf/blank'
require 'wongi-rdf/resource'
require 'wongi-rdf/statement'
require 'wongi-rdf/document'

describe Wongi::RDF::Document do

  subject {
    Wongi::RDF::Document.new
  }

  it 'should be empty initially' do
    should be_empty
    subject.statements.should be_empty
    subject.namespaces.should be_empty
  end

  it 'should provide a quick way to register common namespaces' do
    subject.common!
    subject.lookup( "rdf" ).should == URI.parse( 'http://www.w3.org/1999/02/22-rdf-syntax-ns#' )
  end

  it 'should refuse to replace its base' do
    subject.base = URI.parse( 'http://test/base/' )
    lambda { subject.base = URI.parse( 'http://test/base/' ) }.should_not raise_error(Wongi::RDF::BaseExists)
    lambda { subject.base = URI.parse( 'http://test/base1/' ) }.should raise_error(Wongi::RDF::BaseExists)
  end

  it 'should create a resource from a URI' do
    resource = subject.resource URI.parse( 'http://test/resource' )
    resource.should be_a_kind_of( Wongi::RDF::Resource )
  end

  it 'should create a resource from a parseable string' do
    resource = subject.resource 'http://test/resource'
    resource.should be_a_kind_of( Wongi::RDF::Resource )
  end

  it 'should not create a resource from bad arguments' do
    lambda { subject.resource "something something" }.should raise_error
    lambda { subject.resource 42 }.should raise_error
  end

  it 'should expand qnames' do
    subject.register "test", URI.parse( 'http://test/' )
    resource = subject.resource "test:node1"
    resource.should be_a_kind_of( Wongi::RDF::Resource )
    resource.uri.to_s.should == 'http://test/node1'
  end

  it 'should fail to expand qnames from unknown namespaces' do
    lambda { subject.resource "unknown:node" }.should raise_error
  end

  it 'should accept an array as shorthand' do
    subject.register "test", "http://test/"
    subject << ["test:node1", "test:node2", "test:node3"]
    subject.should have(1).statements
  end

end
