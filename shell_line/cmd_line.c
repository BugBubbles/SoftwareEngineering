#include "cmd_line.h"
#include "malloc.h"
#include "general_list.h"
// 标准命令序列，包含了命令的种类，命令参数列表
typedef struct tag_std_cmdline
{ // 命令的种类，包含了画图命令，变换命令，组合命令等
  cmdtype_t cmdtype;
  // 参数列表，按固定的顺序存储解析得到的参数，每个大小是一样，因为都是union
  glstv_t paralist;
} std_cmdline_t;
typedef struct tag_para
{
  paratype_t paratype;
  paraval_t paraval;
} para_t;
typedef union tag_paraval
{
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
  std_cmdlinev_t std_cmdline = (std_cmdlinev_t)malloc(sizeof(std_cmdline_t));
  std_cmdline->cmdtype_t = cmdtype;
  std_cmdline->paralist = glst_new_bySize(sizeof(paraval_t), paranum);
}