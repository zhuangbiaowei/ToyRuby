require 'rbconfig'

class BuilderShell
  attr_accessor :os,:obj_ext,:exe_ext,:cc,:d,:out,:link,:del

  def initialize
    @os=Config::CONFIG['host_os']
    if @os=='mswin32'
      @obj_ext=".obj"
      @exe_ext=".exe"
      @cc="cl"
      @d=" -DWIN32 "
      @out="-OUT:"
      @link="link"
      @del="del"
    else
      @obj_ext=".o"
      @exe_ext=""
      @cc="gcc"
      @d=""
      @out="-o "
      @link="gcc"
      @del="rm"
    end
  end

  def link out_file,objs
    `#{@link} #{@out}#{out_file}#{@exe_ext} #{objs.join(@obj_ext+" ")+@obj_ext}`
  end

  def del_obj files
    `#{@del} #{files.join(@obj_ext+" ")+@obj_ext}`
  end

  def del_exe files
    `#{@del} #{files.join(@exe_ext+" ")+@exe_ext}`
  end

  def cc files
    files.each {|file| `#{@cc} -c#{@d} #{file}` }
  end
end