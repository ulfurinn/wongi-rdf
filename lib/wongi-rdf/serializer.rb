module Wongi::RDF
  class Serializer

    def initialize document
      @document = document
      @offset = 4
      @offset_method = :spaces
      @ns_counter = 0
      @shorthanded = []
    end

    def serialize
      with_io StringIO.new do
        real_serialize
      end.string
    end

    def serialize_to io
      with_io io do
        real_serialize
      end
    end

    private

    attr_reader :io, :document

    def with_io io
      @io = io
      yield
      io
    ensure
      @io = nil
    end

    def real_serialize
      return unless document
      return unless io.respond_to? :<<
      @offset_level = 0

      if document.base
        io << emit( "@base #{uri_to_s document.base} .\n" )
      end

      extract_namespaces

      document.namespaces.each do |prefix, full|
        io << emit( "@prefix #{prefix}: #{uri_to_s full} .\n" )
      end

      document.statements.each do |st|
        next if @shorthanded.include?( st )
        io << emit( "#{resource_to_s st, :subject} #{resource_to_s st, :predicate} #{resource_to_s st, :object} .\n" )
      end

    end

    def indent
      @offset_level += 1
      yield
    ensure
      @offset_level -= 1
    end

    def emit s
      indentation + s
    end

    def indentation
      if @offset_method == :spaces
        ' ' * ( @offset_level * @offset )
      else
        '\t' * @offset_level
      end
    end

    def uri_to_s uri
      "<#{uri.to_s}>"
    end

    def resource_to_s st, member
      res = st.send member
      case res
      when Resource
        ns, local = *split_uri( res )
        if ns && prefix = document.namespaces.key( ns )
          "#{prefix}:#{local}"
        else
          uri_to_s res.uri
        end
      when Blank
        if member == :object && single_reference?( res, st )
          shorthand res
        else
          "_:#{res.id}"
        end
      end
    end

    def single_reference? blank, ref_st
      conflicting = document.statements.select{ |st| st.predicate == blank || (st == ref_st && st.subject == blank) || (st != ref_st && st.object == blank) }
      conflicting.empty?
    end

    def shorthand blank
      out = "[\n"
      subsequent = false
      indent do
        document.select(blank, nil, nil).each do |st|
          next if @shorthanded.include?( st )
          @shorthanded << st
          out << (subsequent ? ";\n" : "") << emit( "#{resource_to_s st, :predicate} #{resource_to_s st, :object} " )
          subsequent = true
        end
      end
      out << "\n]"
    end

    def extract_namespaces
      document.statements.each do |st|
        extract_namespace st.subject
        extract_namespace st.predicate
        extract_namespace st.object
      end
    end

    def extract_namespace resource
      return unless resource.is_a? Resource
      ns, local = *split_uri(resource)
      unless document.namespaces.key( ns )
        prefix = "ns#{@ns_counter}"
        while document.namespaces.has_key? prefix
          @ns_counter += 1
          prefix = "ns#{@ns_counter}"
        end
        @ns_counter += 1
        document.register prefix, ns
      end
    end

    def split_uri uri
      s = uri.to_s
      last = [ s.rindex('/'), s.rindex('#') ].select { |i| i }.max
      if last
        [URI.parse(s[0..last]), s[(last+1)..-1]]
      end
    end

  end
end
