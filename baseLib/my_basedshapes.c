/*by张国勇，形状库，存放不同的形状信息，用于从源命令行到目标数据体的转换*/
#include "my_shapes.h"
#include "my_list.h"
#include <assert.h>
#include <malloc.h>
#include "my_coordinate.h"
typedef struct point
{
  float x_val;
  float y_val;
} point;
typedef struct line
{
  point point_1;
  point point_2;
} line;
typedef struct circ
{
  point center;
  float radius;
} circ;
typedef struct rect
{
  point left_up;
  point right_down;
} rect;
typedef struct poly
{
  uint num_apex;//顶点数量
  p_list_c p_apex_list;//顶点坐标点列表
} poly;
typedef struct group
{
  uint num_shape;//形状数量
  p_list_c p_shape_list;//形状的指针列表
} gtoup;
void read_point_data(p_point_c point, float *x_val, float *y_val)
{
  *x_val = point->x_val;
  *y_val = point->y_val;
}
void read_line_data(p_line_c line, p_point_v point_1, p_point_v point_2)
{
  my_memcpy(point_1, &(line->point_1), sizeof(point));
  my_memcpy(point_2, &(line->point_2), sizeof(point));
}
//实际上，矩形的存储与线是一样的，都是两个点的坐标，但为了区分，还是单独写一个read_rect_point函数
void read_rect_data(p_rect_c rect, p_point_v point_1, p_point_v point_2)
{
  my_memcpy(point_1, &(rect->left_up), sizeof(point));
  my_memcpy(point_2, &(rect->right_down), sizeof(point));
}
<<<<<<< HEAD:baseLib/my_basedshapes.c
void read_circ_data(p_circ_c circ, p_point_v cnt, float *rad)
{
  my_memcpy(cnt, &(circ->center), sizeof(point));
  *rad = circ->radius;
}
=======
//读取圆数据
void read_circle_radius(p_circ_c circ, float *rad)
{
  my_memcpy(rad, &(circ->radius), sizeof(float));
}
void read_circle_center(p_circ_c circ, p_point_v cnt)
{
   my_memcpy(cnt, &(circ->center), sizeof(point));
}

//读取正多边形数据
void read_poly_radius(p_poly_c poly, float *rad)
{
  my_memcpy(rad, &(poly->radius), sizeof(float));
}
void read_poly_center(p_poly_c poly, p_point_v cnt)
{
  my_memcpy(cnt, &(poly->center), sizeof(point));
}
void read_ploly_num_apex(p_poly_c poly, unsigned int *num_apex)
{
  my_memcpy(num_apex, &(poly->num_apex), sizeof(unsigned int));
}
>>>>>>> 65690ee990f8b73ebb6b0744f9eb6f3732cfc6e2:baseLib/my_shapes.c
