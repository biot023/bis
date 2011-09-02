require "fileutils"
require "yaml"

Given /^I have an output directory "([^\"]*)"$/ do |dirname|
  @output_dir = generate_output_dir( dirname )
end

Given /^I have a biot with a random genome (\d+) integers long$/ do |count|
  @run_attrs ||= {}
  @run_attrs["genome_size"] = count.to_i
end

Given /^my biot has an action count of (\d+)$/ do |count|
  @run_attrs ||= {}
  @run_attrs["action_count"] = count.to_i
end

Given /^I have a sensory array with senses with the following index counts:$/ do |table|
  @run_attrs ||= {}
  @run_attrs["sense_index_counts"] ||= []
  table.rows.each do |(_count)|
    @run_attrs["sense_index_counts"] << _count.to_i
  end
end

Given /^I have the following bis config attributes object:$/ do |table|
  @run_attrs ||= {}
  table.rows.each do |(attr, _value)|
    @run_attrs[attr] = _value.to_i
  end
end

Given /^I generate a bis exec with the biot and config attributes$/ do
  run_runner( { "output_dir" => @output_dir }.merge( @run_attrs ) )
end

Then /^an instruction set should have been generated for my biot$/ do
  %w( exec_desc.yml exec_code ).each do |fname|
    File.exist?( "#{ @output_dir }/#{ fname }" ).should be_true
  end
end

When /^I inspect the generated exec$/ do
  @exec_desc = YAML.load( File.read( "#{ @output_dir }/exec_desc.yml" ) )["exec"]
end

Then /^it should contain between (\d+) and (\d+) individual instructions$/ do |min, max|
  @exec_desc["total_instructions"].should be >= min.to_i
  @exec_desc["total_instructions"].should be <= max.to_i
end

Then /^it should contain between (\d+) and (\d+) sequences of instructions$/ do |min, max|
  @exec_desc["total_instruction_sequences"].should be >= min.to_i
  @exec_desc["total_instruction_sequences"].should be <= max.to_i
end
