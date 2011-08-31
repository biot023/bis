require "yaml"

##------------------------------------------------------------------------------
# VARIABLES:
#
include_dirs = %w( include /usr/local/include )
testlib = "-lboost_unit_test_framework"
additional_cxx_flags = []
additional_ld_flags = []

##------------------------------------------------------------------------------
# CONSTANTS:
#
CC  = "g++-mp-4.6.1"
CXX = "g++-mp-4.6.1"
AR  = "ar cr"
RM  = "rm -f"
CXXFLAGS = %w( -Wall -g -std=c++0x -c ) + include_dirs.map { |incdir| "-I #{ incdir }" }
LDFLAGS  = %w( -lboost_regex )

##------------------------------------------------------------------------------
# FILE LISTS:
#
ALL_SRC = FileList[ "**/*.cpp" ]
SRC = FileList[ "src/**/*.cpp" ]
OBJ = SRC.ext( "o" )
TEST_SRC = FileList[ "test/test_runner.cpp", "test/**/*_test.cpp" ]
TEST_OBJ = TEST_SRC.ext( "o" )
FEAT_SRC = FileList[ "features/*.cpp" ]
FEAT_OBJ = FEAT_SRC.ext( "o" )
CLEAN = FileList[ "features/feature_runner",
                  "test/test_runner",
                  "lib/*.a",
                  "**/*.o",
                  "**/*.d",
                  "**/*.xml",
                  "tmp/*" ]

##------------------------------------------------------------------------------
# HELPERS
#
# Helper method used in dependency injection -- see files section below.
#
def dependencies_for( fname )
  flags = ( CXXFLAGS + [ "-M" ] ).reject { |flag| flag == "-c" }
  `#{ CXX } #{ flags.join( " " ) } #{ fname }`
    .split( /[\\\n ]+/ )
    .reject { |fname| fname =~ /.o.?$/ }
end

##------------------------------------------------------------------------------
# TASKS:
#
task :default => [ :test ]

task :test_mode do
  if ENV["SOLO"]
    test_prereqs = Rake::application["test/test_runner"]
      .instance_variable_get( :@prerequisites )
    test_prereqs.reject! { |f| f =~ /_test\.o$/ }
    test_prereqs << ENV["SOLO"].gsub( ".cpp", ".o" )
    Rake::application["test/test_runner"].
      instance_variable_set( :@prerequisites, test_prereqs );
  end
  additional_cxx_flags << "-DENABLE_BIOT023_IDS"
  additional_ld_flags << "-lboost_unit_test_framework"
  additional_cxx_flags << "-DBOOST_TEST_DYN_LINK"
end

desc "Build the feature runners and test their output against cucumber"
task :cuke => "features/feature_runner" do
  if ENV["PROFILE"]
    sh "cucumber -p #{ ENV['PROFILE'] }"
  else
    sh "cucumber -p default"
  end
end

desc "Build the test runner and run the tests with it"
task :test => [ :test_mode, "test/test_runner" ] do
  sh "./test/test_runner"
end

desc "Clean up all generated files"
task :clean do
  sh "#{ RM } #{ CLEAN.join( " " ) }"
end

task :debug do
  y dependencies_for( "test/game_factory_test.cpp" )
end

##------------------------------------------------------------------------------
# RULES:
#
rule ".o" => ".cpp" do |t|
  flags = CXXFLAGS + additional_cxx_flags
  sh "#{ CXX } #{ flags.join( " " ) } -o #{ t.name } #{ t.source }"
end

##------------------------------------------------------------------------------
# FILES:
#
file "lib/bis.a" => OBJ do |t|
  sh "#{ AR } #{ t.name } #{ t.prerequisites.join( " " ) }"
end

file "features/feature_runner" => [ "lib/bis.a" ] + FEAT_OBJ do |t|
  flags = LDFLAGS + additional_ld_flags
  sh "#{ CC } #{ flags.join( " " ) } #{ t.prerequisites.join( " " ) } -o #{ t.name }"
end

file "test/test_runner" => [ "lib/bis.a" ] + TEST_OBJ do |t|
  flags = LDFLAGS + additional_ld_flags
  sh "#{ CC } #{ flags.join( " " ) } #{ t.prerequisites.join( " " ) } -o #{ t.name }"
end

##
# Generates all dependencies for all .o files.
#
unless Rake::application.top_level_tasks == [ "clean" ]
  ALL_SRC.each do |fname|
    task_name = fname.gsub( /\.cpp$/, ".o" )
    file task_name
    _task = Rake::application[task_name]
    _task.enhance( FileList[ *dependencies_for( fname ) ] )
  end
end
