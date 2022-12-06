#include "my_coordinate.h"
#include "malloc.h"
#include "assert.h"
#include <stdlib.h>
typedef struct tag_coordinate //某一坐标系
{
  int is_top;                       //是不是最顶层的坐标系，是为1，否为0
  float base_point_x, base_point_y; //坐标原点在父坐标系下的位置
  float min_x, max_x, min_y, max_y; //坐标系刻度，即坐标系的最大最小取值
  struct tag_coordinate *parent_coor;   //父坐标系指针
  // float rotate_angle;               //坐标x轴相对于父坐标系逆时针转动的角度
} coordinate_t;

typedef struct tag_ui_coordinate //用户界面坐标系
{
  int scale_x, scale_y;
} ui_coordinate_t;

coordinatev_t new_top_coor(float min_x, float max_x, float min_y, float max_y)
{
  coordinatev_t top_coor = (coordinatev_t)malloc(sizeof(coordinate_t));
  top_coor->is_top = 1;
  top_coor->base_point_x = 0;
  top_coor->base_point_y = 0;
  top_coor->min_x = min_x;
  top_coor->max_x = max_x;
  top_coor->min_y = min_y;
  top_coor->max_y = max_y;
  top_coor->parent_coor = NULL;
}
coordinatev_t new_sub_coor(float base_point_x, float base_point_y,
                           float min_x, float max_x, float min_y, float max_y,
                           coordinatec_t *parent_coor)
{
  coordinatev_t sub_coor = (coordinatev_t)malloc(sizeof(coordinate_t));
  sub_coor->is_top = 0;
  sub_coor->base_point_x = base_point_x;
  sub_coor->base_point_y = base_point_y;
  sub_coor->min_x = min_x;
  sub_coor->max_x = max_x;
  sub_coor->min_y = min_y;
  sub_coor->max_y = max_y;
  sub_coor->parent_coor = NULL;
}
point_t relati_point_to_absol_point(coordinatec_t relati_coor, point_t relati_point)
{
  float relati_base_point_x=relati_coor->base_point_x;
  float relati_base_point_y=relati_coor->base_point_y;
  coordinatec_t parent_coor = relati_coor->parent_coor;
  
}