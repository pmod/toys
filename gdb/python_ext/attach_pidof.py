import gdb
from subprocess import check_output, CalledProcessError

class AttachPidofCommand (gdb.Command):
  "Attach to process by name"

  def __init__ (self):
    super (AttachPidofCommand, self).__init__ ("attach_pidof",
                         gdb.COMMAND_SUPPORT,
                         gdb.COMPLETE_NONE, True)

  def invoke (self, arg, from_tty):
    try:
        pid = check_output(["pidof", arg]).split()[0].decode("utf-8")
    except CalledProcessError:
        gdb.write('process \'%s\' not found\n' % (arg))
        return
    gdb.write('attach to \'%s\' (%s)\n' % (arg, pid))
    gdb.execute('attach %s' % (pid), from_tty)

AttachPidofCommand()
