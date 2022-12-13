#include "my_graph.h"
#include "my_coordinate.h"
#include "manage_coordinate.h"
#include "general_str.h"
#include "malloc.h"
typedef struct tag_graphhead
{
  gstrv_t name;
  coordinatev_t coordinate;
} graphhead_t;

typedef struct _graph_
{
  graphhead_t head;
  glstv_t shapelist;//超形状的指针列表
} _graph_;
static handle_t graph_handle = 0;
graph_t graph_new()
{

  graph_t graph = (graph_t)malloc(sizeof(_graph_));
  gstrv_t name = gstr_new_byCStr("graph");
  gstrv_t char_int = gstr_new(sizeof(char));
  gstr_import_byInt(char_int, graph_handle);
  gstr_appendStr(name, char_int);
  graph->head.name = name;
  gstr_destroy(char_int);
  graph->head.coordinate = get_top();
  graph->shapelist=glst_new(sizeof(supershape_t));
}