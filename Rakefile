#!/usr/bin/env rake
require "bundler/gem_tasks"
require 'rake/extensiontask'

Rake::ExtensionTask.new 'wongi_turtle'

file 'ext/wongi_turtle/TurtleParser.c' => 'ext/wongi_turtle/Turtle.g' do |t|
  `antlr3 #{t.prerequisites.first}`
end
