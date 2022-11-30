#ifndef _GRAPH_
#define _GRAPH_

#ifdef __cplusplus
extern "C"
{
#endif
#include "my_basedshapes.h"
#include <assert.h>
#include "general_list.h"
#include "general_str.h"
  typedef based_shape_t simpleshapetype_t;
  struct tag_simpleshape
  {
    simpleshapetype_t simpleshapetype;
    simpleshapebody_t simpleshapebody;
  };
  typedef union tag_simpleshapebody
  {
    pointv_t point;
    linev_t line;
    circv_t circle;
    polyv_t polygon;
    rectv_t rectangle;
  } simpleshapebody_t;

  typedef glstv_t shapegroup_t;
  typedef enum tag_supershapetype
  {
    simpleshape,
    supershape,
  } supershapetype_t;
  typedef struct tag_supershape
  {
    supershapetype_t supershapetype;
    supershapebody_t supershapebody;
  } supershape_t;
  typedef simpleshapebody_t simpleshape_t;
  typedef union tag_supershapebody
  {
    simpleshape_t simple;
    shapegroup_t group;
  } supershapebody_t;

  typedef struct tag_graph
  {
    graphhead_t head;
    glstv_t shapelst;
  } graph_t;
  typedef struct tag_graphhead
  {
    gstrv_t name;
  } graphhead_t;

#ifdef __cplusplus
}
#endif

#endif