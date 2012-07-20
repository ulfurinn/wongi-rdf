require 'wongi-rdf'

if ARGV.empty?
  puts "Usage: ruby copy.rb <infile> [<outfile>]"
  exit
end

file = ARGV[0]
out = ARGV.size == 1 ? $stdout : File.open( ARGV[1], "w" )

document = Wongi::RDF::Parser.new.parse_file file

Wongi::RDF::Serializer.new( document ).serialize_to out

unless ARGV.empty?
  out.close
end
