#include "cmd_line.h"
#include "malloc.h"
#include "general_list.h"
// 标准命令序列，包含了命令的种类，命令参数列表
typedef struct _std_cmdline_
{ // 命令的种类，包含了画图命令，变换命令，组合命令等
  cmdtype_t cmdtype;
  // 参数列表，按固定的顺序存储解析得到的参数，每个大小是一样，因为都是union
  glstv_t paralist;
} _std_cmdline_;
typedef struct tag_para
{
  paratype_t paratype;
  paraval_t paraval;
} para_t;
typedef union tag_paraval
{
  char *error;
  handle_t handle;
  point_t point;
  point_t center;
  vector_t vector;
  float radius;
  float diameter;
  float length;
  float angle;
} paraval_t;

std_cmdlinev_t std_cmdline_new(cmdtype_t cmdtype, int paranum)
{
  std_cmdlinev_t std_cmdline = (std_cmdlinev_t)malloc(sizeof(_std_cmdline_));
  std_cmdline->cmdtype = cmdtype;
  std_cmdline->paralist = glst_new_bySize(sizeof(paraval_t), paranum);
}
void std_cmdline_destroy(std_cmdlinev_t std_cmdline)
{
  glst_destroy(std_cmdline->paralist);
  free(std_cmdline);
}

void std_cmdline_add_para(std_cmdlinev_t cmdline, paratype_t paratype, float paraval_1, float paraval_2)
{
  para_t *temp = (para_t *)malloc(sizeof(para_t));
  temp->paratype = paratype;
  // paratype类型判断
  if (paratype == _RADIUS)
  {
    temp->paraval.radius = paraval_1;
  }
  else if (paratype == _ANGLE)
  {
    temp->paraval.angle = paraval_1;
  }
  else if (paratype == _LENGTH)
  {
    temp->paraval.length = paraval_1;
  }
  else if (paratype == _HANDLE)
  {
    temp->paraval.handle = paraval_1;
  }

  else if (paratype == _POINT)
  {
    point_t temp_point;
    temp_point.x_val = paraval_1;
    temp_point.y_val = paraval_2;
    temp->paraval.point = temp_point;
  }
  else if (paratype == _CENTER)
  {
    point_t temp_center;
    temp_center.x_val = paraval_1;
    temp_center.y_val = paraval_2;
    temp->paraval.center = temp_center;
  }
  else if (paratype == _VECTOR)
  {
    vector_t temp_vector;
    temp_vector.x_val = paraval_1;
    temp_vector.y_val = paraval_2;
    temp->paraval.center = temp_vector;
  }
  else
  {
    // 报错此处怎么写呢？
    // 答复：我新建了一个报错专用的变量值
    temp->paratype = _ERROR;
    temp->paraval.error = NULL;
  }
  glst_setnode(cmdline->paralist, glst_len(cmdline->paralist), temp);
  free(temp);
}

// handle_id是paratype里的参数吗？
// handle_id是paratype的参数，它就是那个_HANDLE
void std_cmdline_add_handle(std_cmdlinev_t std_cmdline, handle_t handle_id)
{
  // 是的话
  para_t *temp = (para_t *)malloc(sizeof(para_t));
  // 没有paratype哪来的paraval？
  temp->paratype = _HANDLE;
  temp->paraval.handle = handle_id;
  glst_setnode(std_cmdline->paralist, glst_len(std_cmdline->paralist), temp);
  free(temp);
}
int std_cmdline_size()
{
  return sizeof(_std_cmdline_);
}