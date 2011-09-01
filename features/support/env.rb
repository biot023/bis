require "fileutils"

def generate_output_dir( dirname )
  full_dirname = "features/output/#{ dirname }"
  FileUtils.mkdir_p( full_dirname )
  full_dirname
end

class Object

  def __debug
    puts "***** -- #{ self.inspect }"
  end
  
end
