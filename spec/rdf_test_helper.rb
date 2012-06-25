module RdfTestHelper
  def file name
    "spec/input/#{name}.n3"
  end

  def make_test_file string
    File.open file("tmp"), "w" do |io|
      io << string
    end
  end

  def parse_test_file
    @document = @parser.parse_file file("tmp")
  end

  def test_document document
    string = input(document)
    if string.nil?
      raise "Document '#{document}' is not defined"
    end
    make_test_file string
    parse_test_file
  end


end
