#include "general_list.h"
#include "my_basedshapes.h"
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
  supershapetype_t supershapetype;
  supershapebody_t supershapebody;
  handle_t handle;
} _supershape_;

supershape_t shape_new_point(handle_t handle)
{
  // 新建申请内存
  supershape_t new_point_super = (supershape_t)malloc(size_of_shape(_POINT, 0));
  new_point_super->handle = handle;
  // 基本种类确定
  simpleshape_t new_point_simple;
  point_t point;
  new_point_simple.simpleshapebody.point = point;
  new_point_simple.simpleshapetype = _POINT;
  // 超形状种类确定
  new_point_super->supershapetype = _SIMPLE_SHAPE;
  new_point_super->supershapebody.simple = new_point_simple;
}