#ifndef _SUPER_SHAPE_
#define _SUPER_SHAPE_

#ifdef __cplusplus
extern "C"
{
#endif
#include "my_basedshapes.h"
#include "handle.h"
  struct _supershape_;
  typedef struct _supershape_ *supershape_t;
  // 获取超形状的handle
  handle_t get_shape_handle(supershape_t supershape);
  // 获取超形状的字节数
  int size_supershape();
  // 新建一个超形状，有多少个simpleshapebody_t形状就有多少个new函数
  supershape_t shape_new_point(handle_t handle);
  supershape_t shape_new_line(handle_t handle);
  supershape_t shape_new_circle(handle_t handle);
  supershape_t shape_new_polygon(handle_t handle);
  supershape_t shape_new_rectangle(handle_t handle);
  supershape_t shape_new_group(handle_t handle);

  // 各个超形状赋值
  void shape_set_point(supershape_t supershape, point_t point);
  void shape_set_line(supershape_t supershape, line_t line);
  void shape_set_circle(supershape_t supershape, circ_t circle);
  void shape_set_polygon(supershape_t supershape, poly_t poly);
  void shape_set_rectangle(supershape_t supershape, rect_t rect);
  // group操作目前在这一层完成不了，拷贝一份glist，每个元素是一个超形状的指针
  void shape_set_group(supershape_t supershape, glstv_t glist);

  // 各个超形状取值
  point_t shape_get_point(supershape_t supershape);
  line_t shape_get_line(supershape_t supershape);
  circ_t shape_get_circle(supershape_t supershape);
  poly_t shape_get_polygon(supershape_t supershape);
  rect_t shape_get_rectangle(supershape_t supershape);

  // group取值操作
  int shape_get_group_num(supershape_t shapegroup);
  // group的get取回的是一个超形状结构体的指针
  supershape_t shape_get_group_item(supershape_t shapegroup, int pos);

  // 删除一个超形状
  void supershape_destroy(supershape_t supershape);

#ifdef __cplusplus
}
#endif

#endif