#ifndef _COORDINATE_
#define _COORDINATE_

#ifdef __cplusplus
extern "C"
{
#endif
#include "based_geometry.h"

  struct coordinate_t;
  typedef const struct coordinate_t *coordinatec_t;
  typedef struct coordinate_t *coordinatev_t;

  p_coordinatv_t new_top_coor(float min_x, float max_x, float min_y, float max_y); //创建
  p_coordinatv_t new_sub_coor(float base_point_x, float base_point_y,
                              float min_x, float max_x, float min_y, float max_y,
                              coordinatec_t *parent_coor);
  point_t relati_point_to_absol_point(p_coordinate_c relati_coor, point_t relati_point);              //把相对坐标系的点转换为绝对坐标系下的点
  ui_point_t math_point_to_ui_point(coordinatec_t math_coor, point_t math_point, ui_size_t ui_size); //把数学定义的点转换为界面的点
  void destory_coor(coordinatev_t coor);

#ifdef __cplusplus
}
#endif

#endif