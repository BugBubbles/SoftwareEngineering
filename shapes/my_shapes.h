/*by张国勇，形状库，存放不同的形状信息，用于从源命令行到目标数据体的转换*/
#ifndef _MY_SHAPES_
#define _MY_SHAPES_

#ifdef __cplusplus
extern "C"
{
#endif
  //形状类型的定义
  struct point;
  struct line;
  struct circ;
  struct rect;
  struct poly;
  typedef const struct point *p_point_c;
  typedef struct point *p_point_v;
  typedef const struct line *p_line_c;
  typedef struct line *p_line_v;
  typedef const struct circ *p_circ_c;
  typedef struct circ *p_circ_v;
  typedef const struct rect *p_rect_c;
  typedef struct rect *p_rect_v;
  typedef const struct poly *p_poly_c;
  typedef struct poly *p_poly_v;
  //创建点
  p_point_v new_point();
  //读取点命令序列的数据
  void read_point_data(p_point_c point, float *x_val, float *y_val);
  //读取直线命令序列的数据
  void read_line_data(p_line_c line, p_point_v point_1, p_point_v point_2);
  //读取矩形命令序列的数据
<<<<<<< HEAD
  void read_rect_data(p_rect_c rect, p_point_v point_1, p_point_v point_2);
  //读取圆命令序列的数据
  void read_circ_data(p_circ_c circ, p_point_v cnt, float *rad);
  //读取多边形命令序列的数据
  void read_poly_data(p_poly_c poly, p_point_v cnt);
  
=======
  void read_rect_point(p_rect_c rect, p_point_v point_1, p_point_v point_2);
  //读取圆的数据
  void read_circ_radius(p_circ_c circ, float *rad);
  void read_circ_center(p_circ_c circ, p_point_v cnt);
  //读取正多边形数据
  void read_poly_center(p_poly_c poly, p_point_v cnt);
  void read_poly_radius(p_poly_c poly, float *rad);
  void read_poly_num_apex(p_poly_c poly, unsigned int *num_apex);

>>>>>>> 65690ee990f8b73ebb6b0744f9eb6f3732cfc6e2
#ifdef __cplusplus
}
#endif

#endif
