#ifndef _TRANSFORM_
#define _TRANSFORM_

#ifdef __cplusplus
extern "C"
{
#endif
#include "general_list.h"
#include "general_str.h"
#include "my_graph.h"
  typedef gstrv_t cmdline_t;
  typedef;
  //将某一行命令转化为标准命令格式std_cmdline_t
  std_cmdline_v_t transform_txtline_cmdline(gstrc_t cmdline);
  //将某个txt文本文件转成标准命令列表
  std_batcmd_t transform_txtcmd_batcmd(gstrc_t txtcmd);
  //将标准命令列表转成图
  graph_t transform_batcmd_graph(std_batcmd_t batcmd);
#ifdef __cplusplus
}
#endif

#endif