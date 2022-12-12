/*最底层的几何元素库，点*/
#ifndef _BASED_POINTS_
#define _BASED_POINTS_

#ifdef _c_tplusplus
extern "C"
{
#endif
  // 绘图坐标系下的点，坐标值的单位是像素pixel
  typedef struct tag_ui_point
  {
    int x_val;
    int y_val;
  } ui_point_t;
  // 用户界面坐标下的点，坐标值的单位不是像素。
  typedef struct tag_point
  {
    float x_val;
    float y_val;
  } point_t;
  typedef point_t vector_t;

  typedef struct ui_size
  {
    int x_size;
    int y_size;
  } ui_size_t;
  // point_t new_point();
  // point_t new_point_byVal(float x_val, float y_val);
  // ui_point_t new_ui_point();
  // ui_point_t new_ui_point_byVal(int x_val, int y_val);
#ifdef _c_tplusplus
}
#endif

#endif
