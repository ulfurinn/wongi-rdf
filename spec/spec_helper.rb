require 'uri'

$: << "lib"

RSpec::Matchers.define :contain do |*args|
  match do |document|
    document.contains? *args
  end
end
