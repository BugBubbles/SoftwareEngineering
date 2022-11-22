/*by梁耀星，点列表库，存放目标数据的全部点信息，用于直接绘图*/
#include "shape_points.h"
#include "my_shapes.h"
#include <math.h>
#define NUM_POINTS 1000
//从circ_1,到一个圆的点列表,
//点列表由用户定义，假设已经有了
void circ_point_list(p_circ_c circ, float *list_x, float *list_y)
{
  p_point_v cnt = new_point();
  read_circ_center(circ, cnt);
  float rad;
  read_circ_radius(circ, &rad);
  float cnt_x, cnt_y;
  read_point(cnt, &cnt_x, &cnt_y);
  int iter = 0;
  while (iter < NUM_POINTS)
  {
    *(list_x + iter) = cnt_x + rad * cos(360 / NUM_POINTS * iter);
    *(list_y + iter) = cnt_y + rad * sin(360 / NUM_POINTS * iter);
  }
}
void line_point_list(p_line_c line, float *list_x, float *list_y)
{
  p_point_v point_1 = new_point();
  p_point_v point_2 = new_point();

  read_line_point(line, point_1, point_2);

  float point_1_x, point_1_y;
  read_point(point_1, &point_1_x, &point_1_y);
  float point_2_x, point_2_y;
  read_point(point_2, &point_2_x, &point_2_y);

  int iter = 0;
  while (iter < NUM_POINTS)
  {
    *(list_x + iter) = point_1_x + (point_2_x - point_1_x) / NUM_POINTS * iter;
    *(list_y + iter) = point_1_y + (point_2_y - point_1_y) / NUM_POINTS * iter;
  }
}

void rect_point_list(p_rect_c rect, float *list_x, float *list_y)
{
  p_point_v point_1 = new_point();
  p_point_v point_2 = new_point();

  read_rect_point(rect, point_1, point_2);
  float point_1_x, point_1_y;
  read_point(point_1, &point_1_x, &point_1_y);
  float point_2_x, point_2_y;
  read_point(point_2, &point_2_x, &point_2_y);

  int iter = 0;

  int perim_x=abs(point_1_x-point_2_y);   //计算矩形边长以便进行像素数分布
  int perim_y=abs(point_1_y-point_2_y);

  int NUM_POINTS_x=NUM_POINTS*perim_x/(2*(perim_x+perim_y));    //对各边进行像素数分布
  int NUM_POINTS_y=NUM_POINTS*perim_y/(2*(perim_x+perim_y));

  while (iter < NUM_POINTS_x)   //逐边传出点的横坐标列表、点的纵坐标列表
  {
    *(list_x + iter) = point_1_x + (point_2_x - point_1_x) / NUM_POINTS_x * iter;
    *(list_y + iter) = point_1_y ;
    iter++;
  }

  while (iter >= NUM_POINTS_x&&iter < 2*NUM_POINTS_x)
  {
    *(list_x + iter) = point_1_x + (point_2_x - point_1_x) / NUM_POINTS_x * iter;
    *(list_y + iter) = point_2_y ;
    iter++;
  }

  while (iter >= 2*NUM_POINTS_x&&iter < (2*NUM_POINTS_x+NUM_POINTS_y))
  {
    *(list_x + iter) = point_1_x;
    *(list_y + iter) = point_1_y + (point_2_y - point_1_y) / NUM_POINTS_y * iter;
    iter++;
  }

  while (iter >= (2*NUM_POINTS_x+NUM_POINTS_y&&iter < NUM_POINTS))
  {
    *(list_x + iter) = point_2_x;
    *(list_y + iter) = point_1_y + (point_2_y - point_1_y) / NUM_POINTS_y * iter;
    iter++;
  }

}
void poly_point_list();
