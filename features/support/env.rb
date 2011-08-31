require "fileutils"
require "rspec"

World do
  include RSpec::Expectations
  include RSpec::Matchers
end

class Object

  def __debug
    puts "***** -- #{ self.inspect }"
  end
  
end
