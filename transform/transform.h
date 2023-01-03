#ifndef _TRANSFORM_
#define _TRANSFORM_

#ifdef __cplusplus
extern "C"
{
#endif
#include "general_str.h"
#include "my_graph.h"
#include "cmd_list.h"
  //将某一行命令转化为标准命令格式std_cmdline_t
  std_cmdlinev_t transform_txtline_cmdline(gstrc_t cmdline);
  //将某个txt文本文件转成标准命令列表
  std_cmdlist_t transform_txtcmd_cmdlist(gstrc_t txtcmd);
  //将标准命令列表转成图，包括了对图的修改
  graph_t transform_cmdlist_graph(std_cmdlist_t cmdlist);
  //把gstr类型转成命令类型cmdtype_t
  cmdtype_t str_to_cmdtype(gstrc_t cmdname);
#ifdef __cplusplus
}
#endif

#endif