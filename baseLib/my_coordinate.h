/*by梁耀星，坐标及其变换*/
#ifndef _COOR_POINTS_
#define _COOR_POINTS_

#ifdef __cplusplus
extern "C"
{
#endif
  typedef struct point
  {
    float x_val;
    float y_val;
  } point_t;
  typedef struct ui_point
  {
    int x_val;
    int y_val;
  } ui_point_t;

  struct coordinate;
  typedef const struct coordinate *p_coordinate_c;
  typedef struct coordinate *p_coordinate_v;

  typedef struct ui_size
  {
    int x_size;
    int y_size;
  } ui_size_t;

  p_coordinate_v new_top_coor(float min_x, float max_x, float min_y, float max_y); //创建
  p_coordinate_v new_sub_coor(float base_point_x, float base_point_y,
                              float min_x, float max_x, float min_y, float max_y,
                              p_coordinate_c *parent_coor);
  point_t relati_point_to_absol_point(p_coordinate_c relati_coor, point_t relati_point);              //把相对坐标系的点转换为绝对坐标系下的点
  ui_point_t math_point_to_ui_point(p_coordinate_c math_coor, point_t math_point, ui_size_t ui_size); //把数学定义的点转换为界面的点
  void destory_coor(p_coordinate_v coor);
  
#ifdef __cplusplus
}
#endif

#endif