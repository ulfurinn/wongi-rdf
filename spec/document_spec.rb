require 'spec_helper'
require 'wongi-rdf/document'

describe Wongi::RDF::Document do

  it 'should be empty initially' do
    document = Wongi::RDF::Document.new
    document.should be_empty
    document.statements.should be_empty
    document.namespaces.should be_empty
  end

end
