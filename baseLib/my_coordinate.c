#include "my_coordinate.h"


typedef struct coordinate //某一坐标系
{
  int is_top;                       //是不是最顶层的坐标系，是为1，否为0
  float base_point_x, base_point_y; //坐标原点在父坐标系下的位置
  float min_x, max_x, min_y, max_y; //坐标系刻度，即坐标系的最大最小取值
  struct coordinate *parent_coor;   //父坐标系指针
  //float rotate_angle;               //坐标x轴相对于父坐标系逆时针转动的角度

} coordinate;
typedef struct ui_coordinate //用户界面坐标系
{
  // float base_point_x, base_point_y;
  int scale_x, scale_y;
} ui_coordinate;
