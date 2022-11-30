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

//从poly_1,到一个正多边形的点列表,
void poly_point_list(p_poly_c poly, float *list_x, float *list_y)
{
  p_point_v cnt = new_point();
  read_poly_center(poly, cnt);
  float rad;
  read_poly_radius(poly, &rad);
  float cnt_x, cnt_y;
  read_point(cnt, &cnt_x, &cnt_y);
  unsigned int num_apex;
  read_poly_num_apex(poly,&num_apex);
  int iter = 0;

  unsigned int num_point=num_apex;   //端点数和边数是相同的（因为是闭合的）

  float point_x[20]={0};   //定义一个数组来存各顶点的x，y坐标，假设最多有20个顶点
  float point_y[20]={0};
  if (num_point%2==0)  //当有偶数个端点时
  {
     for (int i = 0; i < num_point; i++)
    {
      point_x[i]=sin(360/num_point*(2*i+1)/2);
      point_y[i]=cos(360/num_point*(2*i+1)/2);
    }
  }
  else   //当有奇数个端点时
  {
    for (int i = 0; i < num_point; i++)
    {
      point_x[i]=sin(360/num_point*(2*i)/2);
      point_y[i]=soc(360/num_point*(2*i)/2);

    }
  }
  
  //该逐条边输出了
  for (int i = 0; i < (num_point-1); i++)    //对前num_apex-1条边，符合第一个循环输出点列表
      {
        while (iter>=(NUM_POINTS/num_point*i)&&iter<(NUM_POINTS/num_point*(i+1)))
    {
      *(list_x + iter) = point_x[i] + (point_x[i+1]-point_x[i])/(NUM_POINTS/num_point)*iter;
      *(list_y + iter) = point_y[i] + (point_y[i+1]-point_y[i])/(NUM_POINTS/num_point)*iter;
      iter++;
    }
      }
  for (int i = (num_point-1); i < num_point; i++)   //对最后一条边单独输出点列表
  {
      while (iter>=(NUM_POINTS/num_point*i)&&iter<(NUM_POINTS/num_point*(i+1)))
    {
      *(list_x + iter) = point_x[i] + (point_x[0]-point_x[i])/(NUM_POINTS/num_point)*iter;
      *(list_y + iter) = point_y[i] + (point_y[0]-point_y[i])/(NUM_POINTS/num_point)*iter;
      iter++;
    }
  } 
}  

