require "fileutils"

def generate_output_dir( dirname )
  full_dirname = "features/output/#{ dirname }"
  FileUtils.mkdir_p( full_dirname )
  full_dirname
end

def run_runner( options )
  args = options.map do |_key, _value|
    value = if _value.kind_of?( Array )
              _value.join( "," )
            else
              _value
            end
    key = _key.gsub( "_", "-" )
    "--#{ key } #{ value }"
  end
    .join( " " )
  puts "./features/feature_runner #{ args }"
  retval = `./features/feature_runner #{ args }`
  raise( "The feature runner failed with:\n#{ retval }" ) unless retval =~ /\bDone\./
end

class Object

  def __debug
    puts "***** -- #{ self.inspect }"
  end
  
end
