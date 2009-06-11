require '../../builder_shell'

shell=BuilderShell.new

task :build=>[:test,:trex] do
  shell.link "test",["test","trex"] 
end

task :clean do
  shell.del_obj ["*"]
  shell.del_exe ["test"]
end

task :test do
  shell.cc ["test.c"]
end

task :trex do
  shell.cc ["trex.c"]
end