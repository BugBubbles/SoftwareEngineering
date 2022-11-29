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
  float rad;
  read_circ_data(circ, cnt, &rad);
  float cnt_x, cnt_y;
  read_point_data(cnt, &cnt_x, &cnt_y);
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

  read_line_data(line, point_1, point_2);

  float point_1_x, point_1_y;
  read_point_data(point_1, &point_1_x, &point_1_y);
  float point_2_x, point_2_y;
  read_point_data(point_2, &point_2_x, &point_2_y);

  int iter = 0;
  while (iter < NUM_POINTS)
  {
    *(list_x + iter) = point_1_x + (point_2_x - point_1_x) / NUM_POINTS * iter;
    *(list_y + iter) = point_1_y + (point_2_y - point_1_y) / NUM_POINTS * iter;
  }
}

void rect_point_list();
void poly_point_list();
