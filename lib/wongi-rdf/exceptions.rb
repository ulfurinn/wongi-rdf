module Wongi::RDF

  class BaseExists < Exception
    def initialize message
      super
    end
  end

  class UnknownQNameNamespace < Exception
    def initialize ns, local
      super "Unable to expand #{ns}:#{local}"
    end
  end

end
