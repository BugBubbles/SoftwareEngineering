#ifndef _COORDINATE_
#define _COORDINATE_

#ifdef __cplusplus
extern "C"
{
#endif
#include "based_geometry.h"
  typedef struct tag_ui_coordinate // 用户界面坐标系
  {
    int scale_x, scale_y;
  } ui_coordinate_t;
  struct _coordinate_;
  typedef const struct _coordinate_ *coordinatec_t;
  typedef struct _coordinate_ *coordinatev_t;
  // 创建绝对坐标系
  coordinatev_t new_top_coor(float min_x, float max_x, float min_y, float max_y);
  // 创建一个子坐标系
  coordinatev_t new_sub_coor(float base_point_x, float base_point_y,
                             float min_x, float max_x, float min_y, float max_y);
  // 返回坐标原点
  point_t get_coor_basepnt(coordinatev_t coor);
  // 返回坐标系的尺度
  void get_coor_scale(coordinatev_t coor, float *dst);
  // 返回坐标系的是不是顶层
  int get_coor_is_top(coordinatec_t coor);
  // 仅删除坐标系自己数据，删除子坐标系以下的在管理器中实现
  void destory_coor(coordinatev_t coor);
#ifdef __cplusplus
}
#endif

#endif