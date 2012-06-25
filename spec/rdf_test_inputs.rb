module RdfTestInputs

  def input name
    RdfTestInputs.input[ name ]
  end

  def self.input
    @inputs ||= { }
  end

  input[:empty] = ""

  input[:prefixes] = <<-prefixes_doc
  @prefix ns: <http://test/ns/> .
  prefixes_doc

  input[:base] = <<-base_doc
  @base <http://test/base/> .
  base_doc

end
