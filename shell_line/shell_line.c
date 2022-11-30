#include "shell_line.h"
#include "malloc.h"
typedef enum cmdtype
{
  _NONE, //默认无命令
  _LINE, //直线命令
  _CIRC, //圆周命令
  _RECT, //矩形命令
  _POLY, //多边形命令
  _GROP, //组合命令
} cmdtype_t;
typedef enum paratype
{
  _CENTER,   //圆心参数属性
  _POINT,    //点参数属性
  _RADIUS,   //半径参数属性
  _ANGLE,    //角度参数属性
  _LENGTH,   //长度参数属性
  _DIAMETER, //直径参数属性
  _VECTOR    //向量参数属性
} paratype_t;
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
std_batcmd_t std_cmdline_list_new()
{
  //新建一个glist存放标准化命令行列表
  glstv_t std_batcmd = glst_new(sizeof(std_cmdline_t));
  //返回这个新建的表
  return std_batcmd;
}
//删除一个标准化命令行列表
void std_cmdline_list_del(std_batcmd_t std_batcmd)
{
}
//向命令行列表中添加新的标准化命令
void std_cmdline_list_apd(std_batcmd_t std_batcmd)
{
}