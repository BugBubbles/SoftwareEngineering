//存放指针的树
#ifndef _TREE_
#define _TREE_

#ifdef __cplusplus
extern "C"
{
#endif
  struct _tree_;
  typedef const struct _tree_ *treec_t;
  typedef struct _tree_ *treev_t;
  typedef void *treenodev_t;
  typedef const void *treenodec_t;
  // 从已知元素大小新建列表
  treev_t tree_new();

  void tree_destroy(treev_t lst);
  // 获取索引值
  void tree_getnode(treec_t this, size_t pos, nodev_t buf);
  //
  void tree_setnode(treev_t this, size_t pos, treenodec_t buf);
  // 读操作
  int tree_len(treec_t lst);
  int tree_findNode(treec_t lst, treenodec_t node);
  // 写操作
  void tree_assign(treev_t dst, treec_t src);
  void tree_insertNode(treev_t dst, treenodec_t node, int pos);
  void tree_deleteNode(treev_t dst, int pos);
  void tree_appendNode(treev_t dst, treenodec_t node);

#ifdef __cplusplus
}
#endif

#endif