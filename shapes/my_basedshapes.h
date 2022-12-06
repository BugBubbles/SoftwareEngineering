/*by张国勇，形状库，存放不同的形状信息，用于从源命令行到目标数据体的转换*/
#ifndef _BASED_SHAPES_
#define _BASED_SHAPES_

#ifdef _c_tplusplus
extern "C"
{
#endif
#include "general_list.h"
#include "based_geometry.h"
  typedef glstv_t point_list_t;
  //缺数学空间下各类型的定义
  //缺一个函数，算各种类型的内存空间大小
  typedef enum tag_simpleshapetype
  {
    _LINE,
    _CIRCLE,
    _RECTANGLE,
    _POLYGON
  } simpleshapetype_t;
  typedef struct tag_line
  {
    ui_point_t point_1;
    ui_point_t point_2;
  } line_t;
  typedef struct tag_circ
  {
    ui_point_t center;
    float radius;
  } circ_t;
  typedef struct tag_rect
  {
    ui_point_t left_up;
    ui_point_t right_down;
    float rotate_angle;
  } rect_t;
  typedef struct tag_poly
  {
    int num_apex; //顶点数量
    point_t point_list[1];
  } poly_t;
  
  int size_of_shape(simpleshapetype_t based_shape);
#ifdef _c_tplusplus
}
#endif

#endif
