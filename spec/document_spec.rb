require 'spec_helper'
require 'wongi-rdf/document'

describe Wongi::RDF::Document do

  it 'should be empty initially' do
    document = Wongi::RDF::Document.new
    document.should be_empty
    document.statements.should be_empty
    document.namespaces.should be_empty
  end

  it 'should refuse to replace its base' do
    document = Wongi::RDF::Document.new
    document.base = URI.parse( 'http://test/base/' )
    lambda { document.base = URI.parse( 'http://test/base/' ) }.should_not raise_error(Wongi::RDF::BaseException)
    lambda { document.base = URI.parse( 'http://test/base1/' ) }.should raise_error(Wongi::RDF::BaseException)
  end

end
