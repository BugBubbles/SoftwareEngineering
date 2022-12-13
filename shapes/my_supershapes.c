#include "general_list.h"
#include "my_supershapes.h"
#include "malloc.h"
typedef union tag_simpleshapebody
{
  point_t point;
  line_t line;
  circ_t circle;
  poly_t polygon;
  rect_t rectangle;
} simpleshapebody_t;

typedef struct tag_simpleshape
{
  simpleshapetype_t simpleshapetype;
  simpleshapebody_t simpleshapebody;
} simpleshape_t;

typedef glstv_t shapegroup_t;
typedef enum tag_supershapetype
{
  _SIMPLE_SHAPE,
  _GROUP_SHAPE,
} supershapetype_t;

typedef union tag_supershapebody
{
  simpleshape_t simple;
  shapegroup_t group;
} supershapebody_t;

typedef struct _supershape_
{
  handle_t handle;
  supershapetype_t supershapetype;
  supershapebody_t supershapebody;

} _supershape_;
int size_supershape()
{
  return sizeof(_supershape_);
}
handle_t get_shape_handle(supershape_t supershape)
{
  return supershape->handle;
}
supershape_t shape_new_point(handle_t handle)
{
  // 新建申请内存
  supershape_t new_point_super = (supershape_t)malloc(sizeof(_supershape_));
  new_point_super->handle = handle;
  // 基本种类确定
  simpleshape_t new_point_simple;
  point_t point;
  new_point_simple.simpleshapebody.point = point;
  new_point_simple.simpleshapetype = _POINT;
  // 超形状种类确定
  new_point_super->supershapetype = _SIMPLE_SHAPE;
  new_point_super->supershapebody.simple = new_point_simple;
  // 返回
  return new_point_super;
}
supershape_t shape_new_line(handle_t handle)
{
  // 新建申请内存
  supershape_t new_line_super = (supershape_t)malloc(sizeof(_supershape_));
  new_line_super->handle = handle;
  // 基本种类确定
  simpleshape_t new_line_simple;
  line_t line;
  new_line_simple.simpleshapebody.line = line;
  new_line_simple.simpleshapetype = _LINE;
  // 超形状种类确定
  new_line_super->supershapetype = _SIMPLE_SHAPE;
  new_line_super->supershapebody.simple = new_line_simple;
  // 返回
  return new_line_super;
}
supershape_t shape_new_circle(handle_t handle)
{
  // 新建申请内存
  supershape_t new_circ_super = (supershape_t)malloc(sizeof(_supershape_));
  new_circ_super->handle = handle;
  // 基本种类确定
  simpleshape_t new_circ_simple;
  circ_t circ;
  new_circ_simple.simpleshapebody.circle = circ;
  new_circ_simple.simpleshapetype = _CIRCLE;
  // 超形状种类确定
  new_circ_super->supershapetype = _SIMPLE_SHAPE;
  new_circ_super->supershapebody.simple = new_circ_simple;
  // 返回
  return new_circ_super;
}
supershape_t shape_new_rectangle(handle_t handle)
{
  // 新建申请内存
  supershape_t new_rect_super = (supershape_t)malloc(sizeof(_supershape_));
  new_rect_super->handle = handle;
  // 基本种类确定
  simpleshape_t new_rect_simple;
  rect_t rect;
  new_rect_simple.simpleshapebody.rectangle = rect;
  new_rect_simple.simpleshapetype = _RECTANGLE;
  // 超形状种类确定
  new_rect_super->supershapetype = _SIMPLE_SHAPE;
  new_rect_super->supershapebody.simple = new_rect_simple;
  // 返回
  return new_rect_super;
}
supershape_t shape_new_polygon(handle_t handle)
{
  // 新建申请内存
  supershape_t new_poly_super = (supershape_t)malloc(sizeof(_supershape_));
  new_poly_super->handle = handle;
  // 基本种类确定
  simpleshape_t new_poly_simple;
  poly_t poly;
  new_poly_simple.simpleshapebody.polygon = poly;
  new_poly_simple.simpleshapetype = _POLYGON;
  // 超形状种类确定
  new_poly_super->supershapetype = _SIMPLE_SHAPE;
  new_poly_super->supershapebody.simple = new_poly_simple;
  // 返回
  return new_poly_super;
}
supershape_t shape_new_group(handle_t handle)
{
  // 新建申请内存
  supershape_t new_group_super = (supershape_t)malloc(sizeof(_supershape_));
  new_group_super->handle = handle;
  // 存放的是每一个形状自己
  shapegroup_t group = glst_new(sizeof(simpleshape_t));
  // 超形状种类确定
  new_group_super->supershapetype = _GROUP_SHAPE;
  new_group_super->supershapebody.group = group;
  // 返回
  return new_group_super;
}
void shape_set_point(supershape_t supershape, point_t point)
{
  if (supershape->supershapetype == _SIMPLE_SHAPE)
  {
    if (supershape->supershapebody.simple.simpleshapetype == _POINT)
    {
      supershape->supershapebody.simple.simpleshapebody.point = point;
      return;
    }
  }
  else
  {
    return;
  }
}
void shape_set_line(supershape_t supershape, line_t line)
{
  if (supershape->supershapetype == _SIMPLE_SHAPE)
  {
    if (supershape->supershapebody.simple.simpleshapetype == _LINE)
    {
      supershape->supershapebody.simple.simpleshapebody.line = line;
      return;
    }
  }
  else
  {
    return;
  }
}
void shape_set_circle(supershape_t supershape, circ_t circle)
{
  if (supershape->supershapetype == _SIMPLE_SHAPE)
  {
    if (supershape->supershapebody.simple.simpleshapetype == _CIRCLE)
    {
      supershape->supershapebody.simple.simpleshapebody.circle = circle;
      return;
    }
  }
  else
  {
    return;
  }
}
void shape_set_polygon(supershape_t supershape, poly_t poly)
{
  if (supershape->supershapetype == _SIMPLE_SHAPE)
  {
    if (supershape->supershapebody.simple.simpleshapetype == _POLYGON)
    {
      supershape->supershapebody.simple.simpleshapebody.polygon = poly;
      return;
    }
  }
  else
  {
    return;
  }
}
void shape_set_rectangle(supershape_t supershape, rect_t rect)
{
  if (supershape->supershapetype == _SIMPLE_SHAPE)
  {
    if (supershape->supershapebody.simple.simpleshapetype == _RECTANGLE)
    {
      supershape->supershapebody.simple.simpleshapebody.rectangle = rect;
      return;
    }
  }
  else
  {
    return;
  }
}
void shape_set_group(supershape_t supershape, glstv_t glist)
{
  if (supershape->supershapetype == _GROUP_SHAPE)
  {
    supershape->supershapebody.group = glist;
  }
  else
  {
    return;
  }
}

/*各个超形状取值*/
point_t shape_get_point(supershape_t supershape)
{
  if (supershape->supershapetype == _SIMPLE_SHAPE)
  {
    if (supershape->supershapebody.simple.simpleshapetype == _POINT)
    {
      return supershape->supershapebody.simple.simpleshapebody.point;
    }
  }
  else
  {
    point_t temp;
    temp.x_val = 0;
    temp.y_val = 0;
    return temp;
  }
}
line_t shape_get_line(supershape_t supershape)
{
  if (supershape->supershapetype == _SIMPLE_SHAPE)
  {
    if (supershape->supershapebody.simple.simpleshapetype == _LINE)
    {
      return supershape->supershapebody.simple.simpleshapebody.line;
    }
  }
  else
  {
    ui_point_t point;
    point.x_val = 0;
    point.y_val = 0;
    line_t line;
    line.point_1 = point;
    line.point_2 = point;
    return line;
  }
}
circ_t shape_get_circle(supershape_t supershape)
{
  if (supershape->supershapetype == _SIMPLE_SHAPE)
  {
    if (supershape->supershapebody.simple.simpleshapetype == _CIRCLE)
    {
      return supershape->supershapebody.simple.simpleshapebody.circle;
    }
  }
  else
  {
    ui_point_t point;
    point.x_val = 0;
    point.y_val = 0;
    circ_t circ;
    circ.center = point;
    circ.radius = 0;
    return circ;
  }
}
poly_t shape_get_polygon(supershape_t supershape)
{
  if (supershape->supershapetype == _SIMPLE_SHAPE)
  {
    if (supershape->supershapebody.simple.simpleshapetype == _POLYGON)
    {
      return supershape->supershapebody.simple.simpleshapebody.polygon;
    }
  }
  else
  {
    poly_t poly;
    poly.num_apex = 0;
    poly.point_list = NULL;
    return poly;
  }
}
rect_t shape_get_rectangle(supershape_t supershape)
{
  if (supershape->supershapetype == _SIMPLE_SHAPE)
  {
    if (supershape->supershapebody.simple.simpleshapetype == _RECTANGLE)
    {
      return supershape->supershapebody.simple.simpleshapebody.rectangle;
    }
  }
  else
  {
    ui_point_t point;
    point.x_val = 0;
    point.y_val = 0;
    rect_t rect;
    rect.left_up = point;
    rect.right_down = point;
    rect.rotate_angle = 0;
    return rect;
  }
}
/*group基本取值操作*/
int shape_get_group_num(supershape_t shapegroup)
{
  glstv_t temp_list = shapegroup->supershapebody.group;
  return glst_len(temp_list);
}

supershape_t shape_get_group_item(supershape_t shapegroup, int pos)
{
  glstv_t temp_list = shapegroup->supershapebody.group;
  supershape_t supershape = (supershape_t)malloc(sizeof(_supershape_));
  glst_getnode(temp_list, pos, supershape);
  return supershape;
}
/*删除一个超形状*/
void supershape_destroy(supershape_t supershape)
{
  free(supershape);
  supershape = NULL;
}