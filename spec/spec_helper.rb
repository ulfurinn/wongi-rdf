require 'uri'

$: << "lib"

RSpec.configure do |config|
  config.color_enabled = true
  config.formatter = :documentation # :progress, :html, :textmate
end

RSpec::Matchers.define :contain do |*args|
  match do |document|
    document.contains? *args
  end
end
