#include "cmd_line.h"
#include "transform.h"

// 第一步转换，把txt里面某一行命令string，转化为标准命令序列std_cmdline_t
// 要求：实现参数提取，命令类型提取，错误命令返回空命令并报错，多余的空格 和制表符 去除
std_cmdlinev_t transform_txtline_cmdline(gstrc_t cmdline)
{
  gstrv_t cmdname = gstr_new();
  // 首先一直查找直到遇到左括号，把这部分去除空格以后变成命令名。
  int cmd = gstr_findChr(cmdline, '(');
  gstr_getSub_byPos(cmdline, cmdname, 0, cmd);
  //得到了命令名

  // 然后提取括号里面的东西，并检查括号是否匹配，取得参数的名称与值，编写名称、值的转化程序。
  read name->cmdline_settype() for ()
  {
    para->cmdline_append_para()
  }
}
// 第一步转换，把txt里面的全部行命令string，转化为一串标准命令序列
std_cmdlist_t transform_txtcmd_cmdlist(gstrc_t txtcmd)
{
  batcmd_new();
  for ()
  {
    read a text line;
    parse line->cmdline
    batcmd_append()
  }
}
// 第二步转换，把标准命令序列，转化为图像
graph_t transform_cmdlist_graph(std_cmdlist_t batcmd)
{
  graph_new() for (i = 0->batcmd_lenght() - 1)
  {
    batcmd_getcmdline()->cmdline switch (cmdline_getcmdtype())
    {
    case _LINE:
    graph_addshape() case _CIRC:
    case _MOVE:
    }
  }
}
void transform_txtline_cmdline_line(gstrc_t line)
{
}
cmdtype_t str_to_cmdtype(gstrc_t cmdname){
  char*name=
}