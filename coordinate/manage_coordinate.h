
#ifndef _COOR_MANAGE_
#define _COOR_MANAGE_

#ifdef __cplusplus
extern "C"
{
#endif
  //
  void new_coor_manager();//坐标系的管理器，内部有一个全局静态变量，设计一个树状结构表，方便删除。
  p_coordinate_v get_top();//返回绝对坐标系
  void store_sub_coor(float base_point_x, float base_point_y,
                              float min_x, float max_x, float min_y, float max_y,
                              p_coordinate_c *parent_coor);//在新建坐标系时存入管理器
  void destory_coor_manager(p_coordinate_v coor);//一次性把本坐标系以及本坐标系下的子坐标系全部删除。
#ifdef __cplusplus
}
#endif

#endif