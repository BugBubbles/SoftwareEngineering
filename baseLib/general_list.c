#include "general_list.h"
#include "string.h"
#include <stdlib.h>

#define _DEFINE_POINT_
typedef unsigned int size_t;
// 使用顺序表
/*剩下两种选项是使用指针数组和使用链表*/
typedef unsigned int uint;
typedef char byte;
typedef struct _glst_
{
  // 每个子块实际占用空间
  size_t node_size;
  // 数据部分总共占据的内存空间
  size_t cap_size;
  // 每个子块是一串连续的内存空间，可以直接存一个字符串
  byte *buff;
} _glst_;

glstv_t glst_new(size_t _size)
{ // 默认只创建一个元素那个大的线性表
  glstv_t temp = (glstv_t)malloc(sizeof(_glst_));
  temp->cap_size = _size;
  temp->node_size = _size;
  temp->buff = (byte *)malloc(_size * sizeof(byte));
  return temp;
}
glstv_t glst_new_bySize(size_t nodesize, size_t initsize)
{
  glstv_t temp = (glstv_t)malloc(sizeof(_glst_));
  temp->cap_size = nodesize * initsize;
  temp->node_size = nodesize;
  temp->buff = (byte *)malloc(nodesize * initsize * sizeof(byte));
}
void glst_destroy(glstv_t lst)
{
  free(lst->buff);
  lst->cap_size = 0;
  lst->node_size = 0;
  free(lst);
}
int glst_len(glstc_t s)
{
  if (s == NULL)
  {
    return 0;
  }
  return (s->cap_size / s->node_size);
}
void glst_getnode(glstc_t this, size_t pos, nodev_t buf)
{
  memcpy(buf, pos * (this->node_size), this->buff);
}
void glst_setnode(glstv_t this, size_t pos, nodec_t buf)
{
  memcpy(this->buff, pos * (this->node_size), buf);
}
int glst_findNode(glstc_t lst, nodec_t node)
{
  int iter;
  int len = glst_len(lst);
  for (iter = 0; iter < len; iter += lst->node_size)
  {
    if (memcmp(*(lst->buff + iter), node, lst->node_size) == 0)
    {
      return iter;
    }
  }
  return -1;
}
void glst_assign(glstv_t dst, glstc_t src)
{
  uint dst_len = glst_len(dst);
  uint src_len = glst_len(src);
  uint len = dst_len;
  if (len > src_len)
  {
    len = src_len;
  }
  dst->cap_size = src->node_size * len;
  memcpy(dst->buff, src->buff, dst->cap_size);
}

void glst_insertNode(glstv_t dst, nodec_t node, int pos)
{
  uint len = glst_len(dst);
  if (pos > len || pos < 0)
  {
    return;
  }
  uint clip_size = pos * dst->node_size;
  glstv_t glst_temp = glst_new_bySize(dst->node_size, len + 1);
  memcpy(glst_temp->buff, dst->buff, clip_size);
  memcpy(glst_temp->buff, node, glst_temp->node_size);
  memcpy(glst_temp->buff, (dst->buff + clip_size), dst->cap_size - clip_size);
  glst_destroy(dst);
  dst = glst_temp;
}
void glst_deleteNode(glstv_t dst, int pos)
{
  uint len = glst_len(dst);
  if (pos >= len || pos < 0) // 这里的等号，表明下标是从0开始的
  {
    return;
  }
  uint clip_size = pos * dst->node_size;
  glstv_t glst_temp = glst_new_bySize(dst->node_size, len - 1);
  memcpy(glst_temp->buff, dst->buff, clip_size);
  memcpy(glst_temp->buff, (dst->buff + clip_size + dst->node_size), dst->cap_size - clip_size - dst->node_size);
  glst_destroy(dst);
  dst = glst_temp;
}
void glst_appendNode(glstv_t dst, nodec_t node)
{
  realloc(dst->buff, dst->node_size);
  memcpy(dst->buff + dst->cap_size, node, dst->node_size);
}
void glst_appendLst(glstv_t dst, glstc_t lst)
{
  if (dst->node_size == lst->node_size)
  {
    realloc(dst->buff, lst->cap_size);
    memcpy(dst->buff + glst_len(dst), lst->buff, dst->cap_size);
    dst->cap_size += lst->cap_size;
  }
  else
  {
    return;
  }
}
