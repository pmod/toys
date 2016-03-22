#
# gdb canned sequence for extending "attach" command
# "attach_pidof" allows attach by prog name.
#
# Handles situation when prog not found and when
# several pids found (the first is taken from pidof
# output.
#

define attach_pidof
  if $argc != 1
   help attach_pidof
  else
   shell echo -e "\
set \$PID = "$(echo $(pidof $arg0) 0 | cut -d ' ' -f 1)"\n\
if \$PID > 0\n\
  attach "$(pidof -s $arg0)"\n\
else\n\
  print \"Process '"$arg0"' not found\"\n\
end" > /tmp/gdb.pidof
   source /tmp/gdb.pidof
  end
end
document attach_pidof
Attach to process by name.
Usage: attach_pidof PROG_NAME
end


