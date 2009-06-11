require '../../builder_shell'

shell=BuilderShell.new

task :build=>[:test,:getopt] do
  shell.link "test",["test","getopt"] 
end

task :clean do
  shell.del_obj ["*"]
  shell.del_exe ["test"]
end

task :test do
  shell.cc ["test.c"]
end

task :getopt do
  shell.cc ["getopt.c"]
end