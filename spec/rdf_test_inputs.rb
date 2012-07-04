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

  input[:a] = <<-a_doc
  @prefix test: <http://test/> .
  test:node1 a test:node2 .
  a_doc

  input[:object_list] = <<-object_list_doc
  @prefix test: <http://test/> .
  test:node1 test:node2 test:node31, test:node32, test:node33 .
  object_list_doc

  input[:predicate_list] = <<-predicate_list_doc
  @prefix test: <http://test/> .
  test:node1 test:node21 test:node31 ; test:node22 test:node32 .
  predicate_list_doc

  input[:object_and_predicate_list] = <<-object_and_predicate_list_doc
  @prefix test: <http://test/> .
  test:node1 test:node21 test:node31 ; test:node22 test:node321, test:node322 .
  object_and_predicate_list_doc

  input[:blanks] = <<-blanks_doc
  @prefix test: <http://test/> .
  test:node1 test:node2 _:blank1 .
  blanks_doc

  input[:shortcut] = <<-shortcut_doc
  @prefix test: <http://test/> .
  test:node1 test:node2 [ test:node31 test:node41 ; test:node32 test:node42 ] .
  shortcut_doc

  input[:empty_collection] = <<-empty_collection_doc
  @prefix test: <http://test/> .
  test:node1 test:node2 ( ) .
  empty_collection_doc

  input[:one_element_collection] = <<-one_element_collection_doc
  @prefix test: <http://test/> .
  test:node1 test:node2 ( test:node31 ) .
  one_element_collection_doc

  input[:two_element_collection] = <<-two_element_collection_doc
  @prefix test: <http://test/> .
  test:node1 test:node2 ( test:node31 test:node32 ) .
  two_element_collection_doc
end
