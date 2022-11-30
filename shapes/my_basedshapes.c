#include "general_list.h"
#include "my_basedshapes.h"
// #include "my_list.h"
#include <assert.h>
#include <malloc.h>
typedef struct tag_point
{
  float x_val;
  float y_val;
} point_t;
typedef struct tag_line
{
  point_t point_1;
  point_t point_2;
} line_t;
typedef struct tag_circ
{
  point_t center;
  float radius;
} circ_t;
typedef struct tag_rect
{
  point_t left_up;
  point_t right_down;
} rect_t;
typedef struct tag_poly
{
  int num_apex; //顶点数量
  point_t center;
  float radius;
} poly_t;
void read_point_data(pointc_t point, float *x_val, float *y_val)
{
  *x_val = point->x_val;
  *y_val = point->y_val;
}
void read_line_data(linec_t line, pointv_t point_1, pointv_t point_2)
{
  my_memcpy(point_1, &(line->point_1), sizeof(point_t));
  my_memcpy(point_2, &(line->point_2), sizeof(point_t));
}
//实际上，矩形的存储与线是一样的，都是两个点的坐标，但为了区分，还是单独写一个read_rect_point函数
void read_rect_data(rectc_t rect, pointv_t point_1, pointv_t point_2)
{
  my_memcpy(point_1, &(rect->left_up), sizeof(point_t));
  my_memcpy(point_2, &(rect->right_down), sizeof(point_t));
}
void read_circ_data(circc_t circ, pointv_t cnt, float *rad)
{
  my_memcpy(cnt, &(circ->center), sizeof(point_t));
  *rad = circ->radius;
}
//读取圆数据
void read_circ_radius(circc_t circ, float *rad)
{
  my_memcpy(rad, &(circ->radius), sizeof(float));
}
void read_circ_tenter(circc_t circ, pointv_t cnt)
{
  my_memcpy(cnt, &(circ->center), sizeof(point_t));
}

//读取正多边形数据，这里有点点问题
void read_poly_radius(polyc_t poly, float *rad)
{
  my_memcpy(rad, &(poly->radius), sizeof(float));
}
void read_poly_tenter(polyc_t poly, pointv_t cnt)
{
  my_memcpy(cnt, &(poly->center), sizeof(point_t));
}
void read_poly_num_apex(polyc_t poly, unsigned int *num_apex)
{
  my_memcpy(num_apex, &(poly->num_apex), sizeof(unsigned int));
}
