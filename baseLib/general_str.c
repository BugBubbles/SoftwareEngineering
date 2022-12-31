#include "general_str.h"
#include <string.h>
#include <malloc.h>
#include <assert.h>
#ifndef UINT
#define UINT
typedef unsigned int uint;
#endif
#define _DEFINE_POINT_
// 使用顺序表
/*剩下两种选项是使用指针数组和使用链表*/
typedef char byte;
typedef struct _gstr_
{
  size_t uint_size; // 每个子块实际占用空间
  size_t cap_size;  // 数据部分总共占据的内存空间
  byte *buff;       // 每个子块是一串连续的内存空间，可以直接存一个字符串
} _gstr_;

gstrv_t gstr_new(_size_t nodesize)
{
  // 默认只创建一个元素那个大的线性表
  gstrv_t temp = (gstrv_t)malloc(sizeof(_gstr_));
  temp->cap_size = nodesize;
  temp->uint_size = nodesize;
  temp->buff = (byte *)malloc(nodesize * sizeof(byte));
  return temp;
}
gstrv_t gstr_new_byCStr(const char *s)
{
  char *p = s;
  uint i = 0;
  while (*(p + i) != '\0')
  {
    i++;
  }
  gstrv_t temp = (gstrv_t)malloc(sizeof(_gstr_));
  temp->cap_size = i * sizeof(char);
  temp->uint_size = sizeof(char);
  temp->buff = (byte *)malloc(temp->cap_size * sizeof(byte));
  memcpy(temp->buff, p, temp->cap_size);
  return temp;
}
gstrv_t gstr_new_bySize(_size_t nodesize, _size_t size)
{
  gstrv_t temp = (gstrv_t)malloc(sizeof(_gstr_));
  temp->cap_size = nodesize * size;
  temp->uint_size = nodesize;
  temp->buff = (byte *)malloc(nodesize * size * sizeof(byte));
  return temp;
}
void gstr_destroy(gstrv_t s)
{
  free(s->buff);
  s->cap_size = 0;
  s->uint_size = 0;
  free(s);
}
void gstr_import(gstrv_t this, const char *src)
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
void gstr_export(gstrc_t this, char *dst)
{
  memcpy(dst, this->buff, this->cap_size);
}
void gstr_import_byInt(gstrv_t this, int src)
{
  char *char_int = (char *)malloc(sizeof(char));
  int i = src / 10 + 1;
  while (i--)
  {
    *(char_int + i) = '0' + src % 10;
    src /= 10;
  }
  gstr_import(this, char_int);
  free(char_int);
}
int gstr_len(gstrc_t s)
{
  return (s->cap_size / s->uint_size);
}
// 仅比较字典序
#define _NOT_COMPARABLE_ -2
int gstr_cmp(gstrc_t a, gstrc_t b)
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
int gstr_findChr(gstrc_t s, char c)
{
  if (s->uint_size == sizeof(char))
  {
    char *p = s->buff;
    uint len = gstr_len(s);
    uint i = 0;
    while (i < len)
    {
      if (*(p + i) == c)
      {
        return i; // 有的，返回序列值
      }
      else
      {
        i++;
      }
    }
  }
  return NO_FIND; // 未查到，返回-1;
}
int gstr_findStr(gstrc_t s, const char *sub)
{
  if (s->uint_size == sizeof(char))
  {
    char *p = s->buff;
    uint len = gstr_len(s);
    uint i = 0;
    while (i < len)
    {
      if (memcmp(p + i, sub, sizeof(*sub) / sizeof(char)) == 0)
      {
        return i; // 有的，返回序列值
      }
      else
      {
        i++;
      }
    }
  }
  return NO_FIND; // 未查到，返回-1;
}
void gstr_assign(gstrv_t d, gstrc_t s)
{
  memcpy(d->buff, s->buff, gstr_len(s));
}
void gstr_appendStr(gstrv_t d, gstrc_t s)
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
void gstr_appendChr(gstrv_t d, char c)
{
  if (d->uint_size == sizeof(char))
  {
    realloc(d->buff, 1 * sizeof(char));
    memcpy(d->buff + gstr_len(d), &c, 1 * sizeof(char));
    d->cap_size += 1 * sizeof(char);
  }
  else
  {
    return;
  }
}
void gstr_insertSub(gstrv_t d, gstrc_t s, int pos)
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
void gstr_deleteSub(gstrv_t d, int pos, int len)
{
  uint raw_len = gstr_len(d);
  byte *temp = (byte *)malloc((raw_len - len) * d->uint_size);
  memcpy(temp, d->buff, pos * d->uint_size);
  memcpy(temp + pos, d->buff + pos + len - 1, (raw_len - len - pos) * d->uint_size);
  d->cap_size -= len * d->uint_size;
  free(d->buff);
  d->buff = temp;
}
void gstr_setChr(gstrc_t s, char c, int pos)
{
  char *p = s->buff;
  uint len = gstr_len(s);
  if (pos < 0 || pos > len)
  {
    return;
  }
  else
  {
    *(p + pos) = c;
  }
}
char gstr_getChr(gstrc_t s, int pos)
{
  char *p = s->buff;
  uint len = gstr_len(s);
  if (pos < 0 || pos > len)
  {
    return '\0';
  }
  else
  {
    return *(p + pos);
  }
}
void gstr_setSub(gstrc_t s, const char *sub, int pos)
{
  char *p = s->buff;
  uint len = gstr_len(s);
  if (pos < 0 || pos > len)
  {
    return;
  }
  else
  {
    memcpy(p + pos, sub, sizeof(*sub));
  }
}
void gstr_getSub(gstrc_t s, char *sub, int pos, _size_t size)
{
  char *p = s->buff;
  uint len = gstr_len(s);
  if (pos < 0 || pos > len)
  {
    return;
  }
  else
  {
    memcpy(p + pos, sub, size * sizeof(char));
  }
}
int gstr_skipChr(gstrc_t s, int pos, char c)
{
}