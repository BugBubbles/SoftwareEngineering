#ifndef _BASE_LIB_
#define _BASE_LIB_
#endif
#ifndef UI_SIZE_X
#define UI_SIZE_X 512
#define UI_SIZE_Y 512
#endif
#define ZERO 1e-6
//绘图坐标系下的点，坐标值的单位是像素pixel
typedef struct ui_point
{
  int x_val;
  int y_val;
} ui_point;
//用户界面坐标下的点，坐标值的单位不是像素。
typedef struct dim_2_data
{
  void *x_val;
  void *y_val;
} dim_2_data;
typedef dim_2_data point;
typedef dim_2_data vector;
//存放全部形状的数据
typedef struct shape
{
  //某一形状需要的一个点数据
  ui_point point;
  //某一形状需要的一个向量数据，可以是单位向量也可以不是
  vector vec;

  void *val_1, *val_2, *val_3;
} shape;

//已知一个图形点，一个长度和一个方向矢量，求一个直线方程
int line_equ(shape line, int x_val);
//已知圆心图形点，一个半径长度和一个方向矢量（这个参数先不管，到时候如果要画不完整的圆弧再用），求一个圆的方程
int circle_equ(shape circle, int x_val);
//已知圆心图形点，一个半径长度和一个初始方向矢量，求一个正多边形的方程？
int polygon_equ(shape polygon, int x_val);
//求坐标系的旋转变换
//求坐标系的平移变换
//求坐标系的伸缩变换
