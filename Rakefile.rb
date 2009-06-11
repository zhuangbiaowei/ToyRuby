require 'builder_shell'

shell=BuilderShell.new

task :build=>:temp do
  shell.link "temp",["temp"] 
end

task :clean do
  shell.del_obj ["*"]
  shell.del_exe ["temp"]
end

task :temp do
  shell.cc ["temp.c"]
end