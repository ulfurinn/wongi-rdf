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

  input[:base1] = <<-base_doc
  @base <http://test/base1/> .
  base_doc

  input[:n3] = <<-n3_doc
  <http://test/node1> <http://test/node2> <http://test/node3> .
  n3_doc

  input[:qnames] = <<-qnames_doc
  @prefix test: <http://test/> .
  test:node1 test:node2 test:node3 .
  qnames_doc

end
