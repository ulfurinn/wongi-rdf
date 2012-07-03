module RdfTestHelper

  def parse_test string, document = nil
    @document = @parser.parse_string string, document
  end

  def test_document test_case, document = nil
    string = input(test_case)
    if string.nil?
      raise "Document '#{test_case}' is not defined"
    end
    parse_test string, document
  end

end
