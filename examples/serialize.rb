require 'wongi-rdf'

out = ARGV.empty? ? $stdout : File.open( ARGV[0], "w" )

document = Wongi::RDF::Document.new
document.register "test", URI.parse( 'http://test/' )

document << ["test:node1", "test:node2", "test:node3"]
document << ["test:node3", "http://ns0/nodeX", "http://ns1/nodeY"]

b = document.blank

document << ["test:node1", "test:node4", b]
document << [b, "test:node5", "test:node6"]
document << [b, "test:node7", "test:node8"]

Wongi::RDF::Serializer.new(document).serialize_to out

unless ARGV.empty?
  out.close
end
