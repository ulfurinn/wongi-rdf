describe "the parsing collector" do

  before :each do
    @document = mock "document"
  end

  subject {
    Wongi::RDF::Collector.new @document
  }

  def document
    @document
  end

  it "should remap existing namespaces" do

    # a previously registered namespace
    document.should_receive( :lookup_namespace ).ordered.with( "ns" ).and_return( URI.parse('http://ns/') )

    # asking for a new generated prefix
    document.should_receive( :register ).ordered.with( nil, URI.parse('http://ns1/') ).and_return( "ns0" )

    # suppose we're parsing a document with ns:

    subject.register( "ns", URI.parse( 'http://ns1/' ) ).should == "ns0"
    # this should not touch the document anymore but use the local map
    subject.register( "ns", URI.parse( 'http://ns1/' ) ).should == "ns0"

    # the collector should perform the mapping to the generated prefix
    document.should_receive( :lookup_namespace ).ordered.with( "ns0" ).and_return( URI.parse('http://ns1/') )

    subject.lookup( "ns" ).should == URI.parse( 'http://ns1/' )

    # now suppose out document specifies ns0: as well

    document.should_receive( :lookup_namespace ).ordered.with( "ns0" ).and_return( URI.parse('http://ns1/') )
    document.should_receive( :register ).ordered.with( nil, URI.parse('http://ns2/') ).and_return( "ns1" )

    subject.register( "ns0", URI.parse( 'http://ns2/' ) ).should == "ns1"

    document.should_receive( :lookup_namespace ).ordered.with( "ns1" ).and_return( URI.parse('http://ns2/') )

    subject.lookup( "ns0" ).should == URI.parse( 'http://ns2/' )

  end

end
