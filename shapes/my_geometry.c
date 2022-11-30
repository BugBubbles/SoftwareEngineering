#include "my_geometry.h"
#include <math.h>
#include <malloc.h>
/*
 * This function uses a ui_point, a length value
 * and a unit vector to form a line eqution and
 * returns a quantified coordinate in axe "y".
 *
 * - point   : the beginning point in the ui coordinate（图形坐标下，单位是像素）
 * - len     : the length of line
 * - uni_vec : a unit vector representing the
 *             direction of line.
 * - x_val   : the x axe coordinate of input
 *             point
 *  Output   : the y axe coordinate of input
 *             point
 */
int line_equ(shape line, int x_val)
{
  ui_point point = line.point;
  vector uni_vec = line.vec;
  float dx, dy;
  dx = x_val - point.x_val;
  // zero是非常小的一个数，防止除数为0的
  if (abs(*(float *)uni_vec.x_val) < ZERO)
  {
    dy = 0;
  }
  else
  {
    dy = dx * (*(float *)uni_vec.y_val) / (*(float *)uni_vec.x_val);
  }
  return (int)point.y_val + dy;
}
/*
 * This function uses a ui_point, a length value
 * and a unit vector to form a circle eqution and
 * returns a quantified coordinate in axe "y".
 *
 * - point   : the beginning point in the ui coordinate（图形坐标下，单位是像素）
 * - len     : the length of radius
 * - uni_vec : a unit vector representing the
 *             direction of circle.
 * - x_val   : the x axe coordinate of input
 *             point
 *  Output   : the y axe coordinate of input
 *             point
 */
//只考虑为y值为正的情况，为负另一半取反就可以生成了
// lyx尝试写的
// cbf认为没有问题的
int circle_equ(shape circle, int x_val)
{
  ui_point point = circle.point;
  int *temp_radius = (int *)calloc(1, sizeof(int));
  circle.val_1 = temp_radius;

  float dx, dy;
  dx = x_val - point.x_val;
  dy = sqrt((*(int *)circle.val_1) * (*(int *)circle.val_1) - dx * dx);
  return (int)circle.point.y_val + dy;
}
/*
 * This function uses a ui_point, a length value
 * and a unit vector to form a polygon eqution and
 * returns a quantified coordinate in axe "y".
 *
 * - point   : the beginning point in the ui coordinate（图形坐标下，单位是像素）
 * - len     : the length of radius
 * - uni_vec : a unit vector representing the
 *             direction of circle.
 * - x_val   : the x axe coordinate of input
 *             point
 *  Output   : the y axe coordinate of input
 *             point
 */
//只考虑为y值为正的情况，为负另一半取反就可以生成了
