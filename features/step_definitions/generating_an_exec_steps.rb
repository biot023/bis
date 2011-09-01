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

Given /^my biot has senses with the following sense index counts:$/ do |table|
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
  pending # express the regexp above with the code you wish you had
end
