#ifndef _MY_SHAPES_
#define _MY_SHAPES_

#ifdef __cplusplus
extern "C"
{
#endif
#include "general_list.h"
  struct std_cmdline_t;
  typedef const struct std_cmdline_t *std_cmdline_c_t;
  typedef struct std_cmdline_t *std_cmdline_v_t;
  typedef glstv_t std_batcmd_t;
  //新建一个标准化命令行列表
  std_batcmd_t std_cmdline_list_new();
  //删除一个标准化命令行列表
  void std_cmdline_list_del(std_batcmd_t std_batcmd);
  //向命令行列表中添加新的标准化命令
  void std_cmdline_list_apd(std_batcmd_t std_batcmd);
#ifdef __cplusplus
}
#endif

#endif
