#ifndef _GRAPH_
#define _GRAPH_

#ifdef __cplusplus
extern "C"
{
#endif
#include "my_supershapes.h"
#include "handle.h"
  struct _graph_;
  typedef struct _graph_ *graph_t;
  //新建一个空的图版，图就是超形状的线性组合
  graph_t graph_new();
  //生成handle，取graph的超形状序列最大handle值作为这个图的handle。
  handle_t graph_new_handle(graph_t graph);
  //删除一个图版
  void graph_destroy(graph_t graph);
  //取值，返回图版序列的长度
  int graph_get_num(graph_t graph);
  //输入一个位序，得到这个图版序列中的某一个超形状
  supershape_t graph_get_item(graph_t graph, int pos);
  //添加
  void graph_append(graph_t graph, supershape_t supershape);
  //删除
  void graph_delete(graph_t graph, int pos);
  //利用handle索引结构体，返回pos
  int graph_handle_index(graph_t graph, handle_t handle);

#ifdef __cplusplus
}
#endif

#endif