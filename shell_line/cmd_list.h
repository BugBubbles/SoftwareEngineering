#ifndef _MY_SHAPES_
#define _MY_SHAPES_

#ifdef __cplusplus
extern "C"
{
#endif
#include "general_list.h"
#include "cmd_line.h"
  typedef glstv_t std_cmdlist_t;

  //新建一个标准化命令行列表
  std_cmdlist_t std_cmdlist_new();
  //删除一个标准化命令行列表
  void std_cmdlist_destroy(std_cmdlist_t std_cmdlist);
  //向命令行列表中添加新的一行标准化命令
  void std_cmdlist_append(std_cmdlist_t std_cmdlist, std_cmdlinec_t std_cmdline);
  //获取命令行列表长度
  int std_cmdlist_length(std_cmdlist_t std_cmdlist);
  //获取命令行列表某一行的命令
  std_cmdlinev_t std_cmdlist_getline(std_cmdlist_t std_cmdlist, int pos);
  
#ifdef __cplusplus
}
#endif

#endif
