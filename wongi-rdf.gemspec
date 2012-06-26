# -*- encoding: utf-8 -*-
require File.expand_path('../lib/wongi-rdf/version', __FILE__)

Gem::Specification.new do |gem|
  gem.authors       = ["Valeri Sokolov"]
  gem.email         = ["ulfurinn@ulfurinn.net"]
  gem.description   = %q{A simple RDF parser}
  gem.summary       = %q{A simple RDF parser}
  gem.homepage      = ""

  gem.files         = `git ls-files`.split($\)
  gem.executables   = gem.files.grep(%r{^bin/}).map{ |f| File.basename(f) }
  gem.test_files    = gem.files.grep(%r{^(test|spec|features)/})
  gem.name          = "wongi-rdf"
  gem.require_paths = ["lib"]
  gem.extensions    << "ext/extconf.rb"
  gem.version       = Wongi::RDF::VERSION
end
