
#include "general_list.h"
#include "string.h"
#include <stdlib.h>

#define _DEFINE_POINT_
typedef unsigned int size_t;
//使用顺序表
/*剩下两种选项是使用指针数组和使用链表*/
typedef unsigned int uint;
typedef char byte;
typedef struct _glst_
{
  size_t uint_size; //每个子块实际占用空间
  size_t cap_size;  //数据部分总共占据的内存空间
  byte *buff;       //每个子块是一串连续的内存空间，可以直接存一个字符串
} _glst_;

glstv_t gstr_new(size_t _size)
{ //默认只创建一个元素那个大的线性表
  glstv_t temp = (glstv_t)malloc(sizeof(_glst_));
  temp->cap_size = _size;
  temp->uint_size = _size;
  temp->buff = (byte *)malloc(_size * sizeof(byte));
  return temp;
}
glstv_t gstr_new_byCStr(const char *s)
{
  char *p = s;
  uint i = 0;
  while (*(p + i) != '\0')
  {
    i++;
  }
  glstv_t temp = (glstv_t)malloc(sizeof(_glst_));
  temp->cap_size = i * sizeof(char);
  temp->uint_size = sizeof(char);
  temp->buff = (byte *)malloc(temp->cap_size * sizeof(byte));
  memcpy(temp->buff, p, temp->cap_size);
  return temp;
}
glstv_t gstr_new_bySize(size_t _size, int size)
{
  glstv_t temp = (glstv_t)malloc(sizeof(_glst_));
  temp->cap_size = _size * size;
  temp->uint_size = _size;
  temp->buff = (byte *)malloc(_size * size * sizeof(byte));
}
void gstr_destroy(glstv_t s)
{
  free(s->buff);
  s->cap_size = 0;
  s->uint_size = 0;
  free(s);
}
void gstr_import(glstv_t this, const char *src)
{
  char *p = src;
  uint i = 0;
  while (*(p + i) != '\0')
  {
    i++;
  }
  free(this->buff);
  this->cap_size = i * sizeof(char);
  this->uint_size = sizeof(char);
  this->buff = (byte *)malloc(this->cap_size * sizeof(byte));
  memcpy(this->buff, p, this->cap_size);
}
void gstr_export(glstc_t this, char *dst)
{
  memcpy(dst, this->buff, this->cap_size);
}
int gstr_len(glstc_t s)
{
  return (s->cap_size / s->uint_size);
}
//仅比较字典序
#define _NOT_COMPARABLE_ -2
int gstr_cmp(glstc_t a, glstc_t b)
{
  if (a->uint_size == b->uint_size)
  {
    return memcmp(a->buff, b->buff, a->cap_size);
  }
  else
  {
    return _NOT_COMPARABLE_;
  }
}
#define NO_FIND -1
int gstr_findChr(glstc_t s, char c)
{
  if (s->uint_size == sizeof(char))
  {
    char *p = s->buff;
    size_t len = gstr_len(s);
    size_t i = 0;
    while (i < len)
    {
      if (*(p + i) == c)
      {
        return i; //有的，返回序列值
      }
      else
      {
        i++;
      }
    }
  }
  return NO_FIND; //未查到，返回-1;
}
void gstr_append(glstv_t d, glstc_t s)
{
  if (d->uint_size == s->uint_size)
  {
    realloc(d->buff, s->cap_size);
    memcpy(d->buff + gstr_len(d), s->buff, d->cap_size);
    d->cap_size += s->cap_size;
  }
  else
  {
    return;
  }
}
void gstr_insertSub(glstv_t d, glstc_t s, int pos)
{
  if (d->uint_size == s->uint_size)
  {
    byte *temp = (byte *)malloc(d->cap_size + s->cap_size);
    memcpy(temp, d->buff, pos * d->uint_size);
    memcpy(temp + pos, s->buff, s->cap_size);
    memcpy(temp + pos + gstr_len(s), d->buff + pos, (gstr_len(d) - pos - 1) * d->uint_size);
    realloc(d->buff, s->cap_size);
    d->cap_size += s->cap_size;
    free(d->buff);
    d->buff = temp;
  }
  else
  {
    return;
  }
}
void gstr_deleteSub(glstv_t d, int pos, int len)
{
  uint raw_len = gstr_len(d);
  byte *temp = (byte *)malloc((raw_len - len) * d->uint_size);
  memcpy(temp, d->buff, pos * d->uint_size);
  memcpy(temp + pos, d->buff + pos + len - 1, (raw_len - len - pos) * d->uint_size);
  d->cap_size -= len * d->uint_size;
  free(d->buff);
  d->buff = temp;
}