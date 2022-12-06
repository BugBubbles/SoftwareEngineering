#include "cmd_list.h"
#include "malloc.h"
#include"my_basedshapes.h"
#include"cmd_line.h"

struct tag_std_cmdline
{
  cmdtype_t cmdtype;
  glstv_t paralist;
};
struct tag_para
{
  paratype_t paratype;
  paraval_t paraval;
};
union tag_paraval
{
  point_t point;
  point_t center;
  vector_t vector;
  float radius;
  float diameter;
  float length;
  float angle;
};
typedef union tag_paraval paraval_t;
typedef struct tag_para para_t;
typedef struct tag_std_cmdline std_cmdline_t;

//新建一个标准化命令行列表
std_cmdlist_t std_cmdline_list_new()
{
  //新建一个glist存放标准化命令行列表
  glstv_t std_cmdlist = glst_new(sizeof(std_cmdline_t));
  //返回这个新建的表
  return std_cmdlist;
}
//删除一个标准化命令行列表
void std_cmdline_list_del(std_cmdlist_t std_cmdlist)
{
}
//向命令行列表中添加新的标准化命令
void std_cmdline_list_apd(std_cmdlist_t std_cmdlist)
{
}