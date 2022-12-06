#include "general_list.h"
#include "my_basedshapes.h"
#include "my_supershapes.h"
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
  handle_t handle;
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

typedef struct tag_supershape
{
  supershapetype_t supershapetype;
  supershapebody_t supershapebody;
} tag_supershape;