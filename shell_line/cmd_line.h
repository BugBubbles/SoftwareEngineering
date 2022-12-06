#ifndef _CMD_LINE_
#define _CMD_LINE_

#ifdef __cplusplus
extern "C"
{
#endif
#include "general_list.h"
#include "transform.h"
#include "handle.h"
  typedef enum tag_cmdtype
  {
    _NONE,   //默认无命令
    _NEW,    //新建命令
    _DELETE, //删除命令
    _MODIFY, //修改命令
    _GROUP,  //组合命令
  } cmdtype_t;
  //另一种定义方式：添加图形、删除、修改、组合等，在调用的过程中再调用based_shape的枚举型
  //不包含各个形状句柄的参数
  typedef enum tag_paratype
  {
    _CENTER,   //圆心参数属性
    _POINT,    //点参数属性
    _RADIUS,   //半径参数属性
    _ANGLE,    //角度参数属性
    _LENGTH,   //长度参数属性
    _DIAMETER, //直径参数属性
    _VECTOR,   //向量参数属性
  } paratype_t;

  struct std_cmdline_t;
  typedef const struct std_cmdline_t *std_cmdlinec_t;
  typedef struct std_cmdline_t *std_cmdlinev_t;

  //新建一个新建、组合、删除、修改型标准化命令，如果新建和修改应该调用std_cmdline_add_para，组合和删除应该调用std_cmdline_add_handle
  std_cmdlinev_t std_cmdline_new(cmdtype_t cmdtype, int paranum);

  //删除一个标准化命令
  void std_cmdline_destroy(std_cmdlinev_t std_cmdline);

  //向新建、修改型命令里面添加、设置参数
  void std_cmdline_add_para(std_cmdlinev_t cmdline, paratype_t paratype, float paraval_1, float paraval_2);

  //向组合、删除型命令里面添加、设置参数
  void std_cmdline_add_handle(std_cmdlinev_t std_cmdline, handle_t handle_id);
#ifdef __cplusplus
}
#endif

#endif
