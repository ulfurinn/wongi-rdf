module RdfTestHelper
  def file name
    "spec/input/#{name}.n3"
  end

  def make_test_file string
    File.open file("tmp"), "w" do |io|
      io << string
    end
  end

  def parse_test_file document = nil
    @document = @parser.parse_file file("tmp"), document
  end

  def test_document test_case, document = nil
    string = input(test_case)
    if string.nil?
      raise "Document '#{test_case}' is not defined"
    end
    make_test_file string
    parse_test_file document
  end


end
