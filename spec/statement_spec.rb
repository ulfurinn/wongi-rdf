require 'wongi-rdf/document'
require 'wongi-rdf/statement'
require 'wongi-rdf/resource'

describe Wongi::RDF::Statement do

  before :each do
    @document = Wongi::RDF::Document.new
    @document.register "test", URI.parse("http://test/")
  end

  it 'should initialize using shorthand' do
    statement = Wongi::RDF::Statement.new "test:node1", "test:node2", "test:node3", @document

    [:subject, :predicate, :object].each do |node|
      statement.send(node).should be_a_kind_of( Wongi::RDF::Resource )
    end

    statement.subject.uri.to_s.should == 'http://test/node1'
    statement.predicate.uri.to_s.should == 'http://test/node2'
    statement.object.uri.to_s.should == 'http://test/node3'
  end

  it 'should compare equality' do
    statement1 = Wongi::RDF::Statement.new "test:node1", "test:node2", "test:node3", @document
    statement2 = Wongi::RDF::Statement.new "test:node1", "test:node2", "test:node3", @document

    statement1.should == statement2
  end
  
end
