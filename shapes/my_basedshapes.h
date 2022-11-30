/*by张国勇，形状库，存放不同的形状信息，用于从源命令行到目标数据体的转换*/
#ifndef _BASED_SHAPES_
#define _BASED_SHAPES_

#ifdef _c_tplusplus
extern "C"
{
#endif
  //形状类型的定义
  struct tag_point;
  struct tag_line;
  struct tag_circ;
  struct tag_rect;
  struct tag_poly;
  typedef const struct tag_point *pointc_t;
  typedef struct tag_point *pointv_t;
  typedef const struct tag_line *linec_t;
  typedef struct tag_line *linev_t;
  typedef const struct tag_circ *circc_t;
  typedef struct tag_circ *circv_t;
  typedef const struct tag_rect *rectc_t;
  typedef struct tag_rect *rectv_t;
  typedef const struct tag_poly *polyc_t;
  typedef struct tag_poly *polyv_t;
  //创建点
  pointv_t new_point();
  //读取点命令序列的数据
  void read_point_data(pointc_t point, float *xv_tal, float *yv_tal);
  //读取直线命令序列的数据
  void read_line_data(linec_t line, pointv_t point_1, pointv_t point_2);
  //读取矩形命令序列的数据
  void read_rect_data(rectc_t rect, pointv_t point_1, pointv_t point_2);
  //读取圆命令序列的数据
  void read_circ_data(circc_t circ, pointv_t cnt, float *rad);
  //读取多边形命令序列的数据
  void read_poly_data(polyc_t poly, pointv_t cnt);
  void read_rect_point(rectc_t rect, pointv_t point_1, pointv_t point_2);
  //读取圆的数据
  void read_circ_radius(circc_t circ, float *rad);
  void read_circ_tenter(circc_t circ, pointv_t cnt);
  //读取正多边形数据
  void read_poly_tenter(polyc_t poly, pointv_t cnt);
  void read_poly_radius(polyc_t poly, float *rad);
  void read_poly_num_apex(polyc_t poly, unsigned int *num_apex);
#ifdef _c_tplusplus
}
#endif

#endif
