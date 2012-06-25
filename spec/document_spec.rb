require 'spec_helper'
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

  it 'should refuse to replace its base' do
    subject.base = URI.parse( 'http://test/base/' )
    lambda { subject.base = URI.parse( 'http://test/base/' ) }.should_not raise_error(Wongi::RDF::BaseException)
    lambda { subject.base = URI.parse( 'http://test/base1/' ) }.should raise_error(Wongi::RDF::BaseException)
  end

  it 'should create a resource from a URI' do
    resource = subject.resource URI.parse( 'http://test/resource' )
    resource.should be_a_kind_of( Wongi::RDF::Resource )
  end

  it 'should not create a resource from bad arguments' do
    lambda { subject.resource 42 }.should raise_error
  end

end
