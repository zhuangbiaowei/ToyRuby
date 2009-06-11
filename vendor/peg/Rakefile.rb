require '../../builder_shell'

shell=BuilderShell.new

task :build=>[:peg,:leg]

if shell.os=="mswin32"
  task :peg=>[:peg_o,:tree,:compile,:getopt,:libgen] do 
    shell.link "peg",["peg","tree","compile","getopt","libgen"]
  end
else
  task :peg=>[:peg_o,:tree,:compile] do 
    shell.link "peg",["peg","tree","compile"]
  end
end

if shell.os=="mswin32"
  task :leg=>[:leg_o,:tree,:compile,:getopt,:libgen] do 
    shell.link "leg",["leg","tree","compile","getopt","libgen"]
  end
else
  task :leg=>[:leg_o,:tree,:compile] do 
    shell.link "leg",["leg","tree","compile"]
  end  
end

task :clean do
  shell.del_obj ["*"]
  shell.del_exe ["peg","leg"]
end

task :peg_o do
  shell.cc ["peg.c"]
end

task :leg_o do
  shell.cc ["leg.c"]
end

task :getopt do
  shell.cc ["getopt.c"]
end

task :libgen do
  shell.cc ["libgen.c"]
end

task :tree do
  shell.cc ["tree.c"]
end

task :compile do
  shell.cc ["compile.c"]
end