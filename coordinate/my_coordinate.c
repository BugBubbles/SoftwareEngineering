#include "my_coordinate.h"
#include "malloc.h"
#include "general_list.h"
#ifndef TOP_HANDLE
#define TOP_HANDLE 0
#endif
typedef struct _coordinate_ // 某一坐标系
{
  int is_top;                       // 是不是最顶层的坐标系，是为1，否为0
  float base_point_x, base_point_y; // 坐标原点在父坐标系下的位置
  float min_x, max_x, min_y, max_y; // 坐标系刻度，即坐标系的最大最小取值
  // float rotate_angle;               //坐标x轴相对于父坐标系逆时针转动的角度
} _coordinate_;
static coor_handle = 0;
coordinatev_t new_top_coor(float min_x, float max_x, float min_y, float max_y)
{
  coordinatev_t top_coor = (coordinatev_t)malloc(sizeof(_coordinate_));
  top_coor->is_top = 1; // 顶层为1
  top_coor->base_point_x = 0;
  top_coor->base_point_y = 0;
  top_coor->min_x = min_x;
  top_coor->max_x = max_x;
  top_coor->min_y = min_y;
  top_coor->max_y = max_y;
}
coordinatev_t new_sub_coor(float base_point_x, float base_point_y, float min_x, float max_x, float min_y, float max_y)
{
  coordinatev_t sub_coor = (coordinatev_t)malloc(sizeof(_coordinate_));
  sub_coor->is_top = 0; // 表示不是顶层，在管理器中赋值为具体的handle
  sub_coor->base_point_x = base_point_x;
  sub_coor->base_point_y = base_point_y;
  sub_coor->min_x = min_x;
  sub_coor->max_x = max_x;
  sub_coor->min_y = min_y;
  sub_coor->max_y = max_y;
  return sub_coor;//暂时不用可以改成NULL
}
point_t get_coor_basepnt(coordinatev_t coor)
{
  point_t temp;
  temp.x_val = coor->base_point_x;
  temp.y_val = coor->base_point_y;
}
int get_coor_is_top(coordinatec_t coor)
{
  return coor->is_top;
}
void get_coor_scale(coordinatev_t coor, float *dst)
{
  *(dst) = coor->min_x;
  *(dst + 1) = coor->max_x;
  *(dst + 2) = coor->min_y;
  *(dst + 3) = coor->max_y;
}
// 仅删除自己，删除子坐标系以下的在管理器中实现
void destory_coor(coordinatev_t coor)
{
  free(coor);
}