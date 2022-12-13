#include "my_graph.h"
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
  glstv_t shapelist; // 超形状的指针列表
} _graph_;
// 全局静态变量
static handle_t graph_handle = 0;
graph_t graph_new()
{
  graph_t graph = (graph_t)malloc(sizeof(_graph_));
  gstrv_t name = gstr_new_byCStr("graph");
  gstrv_t char_int = gstr_new(sizeof(char));
  // 按编号命名
  gstr_import_byInt(char_int, graph_handle);
  gstr_appendStr(name, char_int);
  graph->head.name = name;
  gstr_destroy(char_int);
  // 默认定义在绝对坐标系下
  graph->head.coordinate = get_top();
  graph->shapelist = glst_new(sizeof(supershape_t));
  return graph;
}
// handle一直保持增加，越后面添加的handle值越大
handle_t graph_new_handle(graph_t graph)
{ // 以尾部的handle值代表这个图的handle值
  int len = glst_len(graph->shapelist);
  supershape_t temp_super = (supershape_t)malloc(size_supershape());
  glst_getnode(graph->shapelist, len, temp_super);
  return get_shape_handle(temp_super);
}
void graph_destroy(graph_t graph)
{
  gstr_destroy(graph->head.name);
  glst_destroy(graph->shapelist);
  free(graph);
}
int graph_get_num(graph_t graph)
{
  return glst_len(graph->shapelist);
}
supershape_t graph_get_item(graph_t graph, int pos)
{
  supershape_t temp_super = (supershape_t)malloc(size_supershape());
  glst_getnode(graph->shapelist, pos, temp_super);
  return temp_super;
}
void graph_append(graph_t graph, supershape_t supershape)
{
  glst_appendNode(graph->shapelist, supershape);
}
void graph_delete(graph_t graph, int pos)
{
  glst_deleteNode(graph->shapelist, pos);
}
int graph_handle_index(graph_t graph, handle_t handle)
{
  int len = glst_len(graph->shapelist);
  int i;
  supershape_t temp_super = (supershape_t)malloc(size_supershape());
  for (i = 0; i < len; i++)
  {
    glst_getnode(graph->shapelist, i, temp_super);
    if (get_shape_handle(temp_super) == handle)
    {
      free(temp_super);
      return i;
    }
  }
  free(temp_super);
  return -1; // 表示未查到
}