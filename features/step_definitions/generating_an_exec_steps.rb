Given /^I have an output directory "([^\"]*)"$/ do |dirname|
  @output_dir = generate_output_dir( dirname )
end
