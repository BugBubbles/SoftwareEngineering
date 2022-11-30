#include "shell_line.h"
#include "transform.h"
std_cmdline_v_t transform_txtline_cmdline(gstrc_t cmdline)
{
  cmdline_new()
      read name->cmdline_settype() for ()
  {
    para->cmdline_append_para()
  }
}

std_batcmd_t transform_txtcmd_batcmd(gstrc_t txtcmd)
{
  batcmd_new() for ()
  {
    read a text line;
    parse line->cmdline
    batcmd_append()
  }
}

graph_t transform_batcmd_graph(std_batcmd_t batcmd)
{
  graph_new() for (i = 0->batcmd_lenght() - 1)
  {
    batcmd_getcmdline()->cmdline switch (cmdline_getcmdtype())
    {
    case _LINE:
      graph_addshape() case _CIRC : case _MOVE:
    }
  }
}
