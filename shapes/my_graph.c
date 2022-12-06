#include "my_graph.h"
#include "my_coordinate.h"
#include "general_str.h"
typedef struct tag_graphhead
{
  gstrv_t name;
  coordinatev_t coordinate;
} graphhead_t;

typedef struct tag_graph
{
  graphhead_t head;
  glstv_t shapelist;
} tag_graph;
