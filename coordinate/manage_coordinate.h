
#ifndef _COOR_MANAGE_
#define _COOR_MANAGE_

#ifdef __cplusplus
extern "C"
{
#endif
#include "my_coordinate.h"
  struct _coor_manager_;
  typedef struct _coor_manager_ *coor_manager_t;
  void new_coor_manager(coordinatec_t top_coor);                     // 坐标系的管理器，内部有一个全局静态变量，设计hash结构表，方便删除。
  coordinatev_t get_top();                                           // 返回绝对坐标系
  void store_sub_coor(coordinatec_t above_coor, coordinatec_t coor); // 在新建坐标系时存入管理器
  void destory_coor_manager(coordinatev_t coor);                     // 一次性把本坐标系以及本坐标系下的子坐标系全部删除。
  // 把相对坐标系的点转换为绝对坐标系下的点
  point_t relati_point_to_absol_point(coordinatec_t relati_coor, point_t relati_point);
  // 把数学定义的点转换为界面的点
  ui_point_t math_point_to_ui_point(coordinatec_t math_coor, point_t math_point, ui_coordinate_t ui_coordinate);
#ifdef __cplusplus
}
#endif

#endif