# Wongi::RDF

Parses and serialises [Turtle](http://en.wikipedia.org/wiki/Turtle_%28syntax%29) documents.

## Installation

Add this line to your application's Gemfile:

    gem 'wongi-rdf'

And then execute:

    $ bundle

Or install it yourself as:

    $ gem install wongi-rdf

Building the gem requires the [ANTLR 3.4 C runtime](http://www.antlr.org/download/C). Some Linux distributions, such as Ubuntu and its derivatives, only provide older versions that are not compatible.

## Usage

### Parsing a document

```ruby
parser = Wongi::RDF::Parser.new
document1 = parser.parse_file file_name
document2 = parser.parse_string document_string
```

### Creating a document by hand



### Serialising

```ruby
s = Wongi::RDF::Serializer.new document
document_string = s.serialize
s.serialize_to io
```end

## Contributing

1. Fork it
2. Create your feature branch (`git checkout -b my-new-feature`)
3. Commit your changes (`git commit -am 'Added some feature'`)
4. Push to the branch (`git push origin my-new-feature`)
5. Create new Pull Request
