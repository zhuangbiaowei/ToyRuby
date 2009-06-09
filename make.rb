require 'rbconfig'
HOST_OS=Config::CONFIG['host_os']
if HOST_OS=='mswin32'
  `cl -c /DWIN32 temp.c`
  `cl temp.obj`
else
  `gcc -c temp.c`
  `gcc -o temp temp.o`
end