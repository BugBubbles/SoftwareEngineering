#include "my_basedshapes.h"
int size_of_shape(simpleshapetype_t based_shape, int num_apex)
{
  switch (based_shape)
  {
  case _POINT:
    return sizeof(point_t);
  case _LINE:
    return sizeof(line_t);
  case _CIRCLE:
    return sizeof(circ_t);
  case _RECTANGLE:
    return sizeof(rect_t);
  case _POLYGON:
    return sizeof(num_apex) + num_apex * sizeof(point_t);
  default:
    return 0;
  }
}
