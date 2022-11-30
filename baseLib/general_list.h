#ifndef _GLIST_
#define _GLIST_

#ifdef __cplusplus
extern "C"
{
#endif
  typedef unsigned int size_t;
  // 接口数据类型
  struct _glst_;                        // 不完全类型，无法直接定义变量
  typedef struct _glst_ *glstv_t;       // 变量指针
  typedef const struct _glst_ *glstc_t; // 常量指针
  typedef void *nodev_t;
  typedef const void *nodec_t;
  // 构造/析构
  glstv_t glst_new(size_t nodesize); // sizeof(nodetype)
  glstv_t glst_new_bySize(size_t nodesize, size_t initsize);
  void glst_destroy(glstv_t lst);
  // []
  void glst_getnode(glstc_t this, size_t pos, nodev_t buf);
  void glst_setnode(glstv_t this, size_t pos, nodec_t buf);
  // 读操作
  int glst_len(glstc_t lst);
  int glst_findNode(glstc_t lst, nodec_t node);
  // 写操作
  void glst_assign(glstv_t dst, glstc_t src);
  void glst_insertNode(glstv_t dst, nodec_t node, int pos);
  void glst_deleteNode(glstv_t dst, int pos);
  void glst_appendNode(glstv_t dst, nodec_t node);
  void glst_appendLst(glstv_t dst, glstc_t lst);

#ifdef __cplusplus
}
#endif

#endif