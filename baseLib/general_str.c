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
  size_t cap_size; // 数据部分总共占据的内存空间
  byte *buff;      // 每个子块是一串连续的内存空间，可以直接存一个字符串
} _gstr_;

gstrv_t gstr_new()
{
  // 默认只创建0个元素那个大的线性表
  gstrv_t temp = (gstrv_t)malloc(sizeof(_gstr_));
  temp->cap_size = 0;
  temp->buff = NULL;
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
  temp->buff = (byte *)malloc(temp->cap_size * sizeof(byte));
  memcpy(temp->buff, p, temp->cap_size);
  return temp;
}
gstrv_t gstr_new_bySize(_size_t gstrsize)
{
  gstrv_t temp = (gstrv_t)malloc(sizeof(_gstr_));
  temp->cap_size = gstrsize * sizeof(char);
  temp->buff = (byte *)malloc(sizeof(char) * gstrsize * sizeof(byte));
  return temp;
}
void gstr_destroy(gstrv_t s)
{
  free(s->buff);
  s->cap_size = 0;
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
  return (s->cap_size / sizeof(char));
}
// 仅比较字典序
int gstr_cmp(gstrc_t a, gstrc_t b)
{
  return memcmp(a->buff, b->buff, a->cap_size);
}
#define NO_FIND -1
int gstr_findChr(gstrc_t s, char c)
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
  return NO_FIND; // 未查到，返回-1;
}
int gstr_findStr(gstrc_t s, gstrc_t sub)
{
  char *p = s->buff;
  uint len = gstr_len(s);
  uint i = 0;
  while (i < len)
  {
    if (memcmp(p + i, sub->buff, sub->cap_size) == 0)
    {
      return i; // 有的，返回序列值
    }
    else
    {
      i++;
    }
  }
  return NO_FIND; // 未查到，返回-1;
}
void gstr_assign(gstrv_t d, gstrc_t s)
{
  int d_len = gstr_len(d), s_len = gstr_len(s);
  if (d_len < s_len)
  {
    memcpy(d->buff, s->buff, d_len);
  }
  else
  {
    memcpy(d->buff, s->buff, s_len);
  }
}
void gstr_appendStr(gstrv_t d, gstrc_t s)
{
  realloc(d->buff, s->cap_size);
  memcpy(d->buff + gstr_len(d), s->buff, d->cap_size);
  d->cap_size += s->cap_size;
}
void gstr_appendChr(gstrv_t d, char c)
{
  realloc(d->buff, 1 * sizeof(char));
  memcpy(d->buff + gstr_len(d), &c, 1 * sizeof(char));
  d->cap_size += 1 * sizeof(char);
}
void gstr_insertSub(gstrv_t d, gstrc_t s, int pos)
{
  byte *temp = (byte *)malloc(d->cap_size + s->cap_size);
  memcpy(temp, d->buff, pos * sizeof(char));
  memcpy(temp + pos, s->buff, s->cap_size);
  memcpy(temp + pos + gstr_len(s), d->buff + pos, (gstr_len(d) - pos - 1) * sizeof(char));
  realloc(d->buff, s->cap_size);
  d->cap_size += s->cap_size;
  free(d->buff);
  d->buff = temp;
}
void gstr_deleteSub(gstrv_t d, int pos, int len)
{
  uint raw_len = gstr_len(d);
  byte *temp = (byte *)malloc((raw_len - len) * sizeof(char));
  memcpy(temp, d->buff, pos * sizeof(char));
  memcpy(temp + pos, d->buff + pos + len - 1, (raw_len - len - pos) * sizeof(char));
  d->cap_size -= len * sizeof(char);
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
void gstr_setSub(gstrc_t s, gstrc_t sub, int pos)
{
  char *p = s->buff;
  uint len = gstr_len(s);
  if (pos < 0 || pos > len)
  {
    return;
  }
  else
  {
    memcpy(p + pos, sub->buff, sub->cap_size);
  }
}
void gstr_getSub(gstrc_t s, gstrc_t sub, int pos, _size_t size)
{
  char *p = s->buff;
  uint len = gstr_len(s);
  if (pos < 0 || pos > len)
  {
    return;
  }
  else
  {
    memcpy(p + pos, sub->buff, sub->cap_size);
  }
}
int gstr_skipChr(gstrc_t s, int pos, char c)
{
  char *p = s->buff;
  uint len = gstr_len(s);
  if (pos < 0 || pos > len)
  {
    return NO_FIND;
  }
  else
  {
    uint i = pos;
    while (i < len)
    {
      if (*(p + i) != c)
      {
        return i; // 有的，返回序列值
      }
      else
      {
        i++;
      }
    }
    return NO_FIND;
  }
}
int gstr_skipSpChr(gstrc_t s, int pos)
{
  char *p = s->buff;
  uint len = gstr_len(s);
  if (pos < 0 || pos > len)
  {
    return NO_FIND;
  }
  else
  {
    uint i = pos + 1;
    while (i < len)
    {
      if (*(p + i) != *(p + pos))
      {
        return i; // 有的，返回序列值
      }
      else
      {
        i++;
      }
    }
    return NO_FIND;
  }
}
int gstr_findStrFrom(gstrc_t s, int pos, gstrc_t sub)
{
  char *p = s->buff;
  uint len = gstr_len(s);
  if (pos < 0 || pos > len)
  {
    return NO_FIND;
  }
  else
  {
    uint i = pos + 1;
    while (i < len)
    {
      if (memcmp(p + pos, sub->buff, sub->cap_size) == 0)
      {
        return i; // 有的，返回序列值
      }
      else
      {
        i++;
      }
    }
    return NO_FIND;
  }
}
int gstr_skipSpFindChr(gstrc_t s, int pos, char c)
{
  char *p = s->buff;
  uint len = gstr_len(s);
  if (pos < 0 || pos > len)
  {
    return NO_FIND;
  }
  else
  {
    uint i = pos + 1;
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
    return NO_FIND;
  }
}
int gstr_skipSpFindStr(gstrc_t s, int pos, gstrc_t sub)
{
  uint len = gstr_len(s);
  if (pos < 0 || pos > len)
  {
    return NO_FIND;
  }
  else
  {
    uint i = pos + 1;
    gstrv_t dst = gstr_new();
    gstr_removeSpPos(s, pos);
    char *p = s->buff;
    while (i < len)
    {
      if (memcmp(p + pos, sub->buff, sub->cap_size) == 0)
      {
        return i; // 有的，返回序列值
      }
      else
      {
        i++;
      }
    }
    return NO_FIND;
  }
}
int gstr_replaceOneChr(gstrv_t dst, char raw_c, char new_c, int pos)
{
  char *src_p = dst->buff;
  uint len = gstr_len(dst);
  if (pos < 0 || pos > len)
  {
    return NO_FIND;
  }
  else
  {
    uint i = pos + 1;
    while ((i = gstr_skipSpFindChr(dst, i, raw_c)) != NO_FIND)
    {
      *(src_p + i) = new_c;
    }
    return 0;
  }
}
int gstr_replaceAllChr(gstrv_t dst, char raw_c, char new_c)
{
  char *src_p = dst->buff;
  uint i = 0;
  while ((i = gstr_skipSpFindChr(dst, i, raw_c)) != NO_FIND)
  {
    *(src_p + i) = new_c;
  }
  return 0;
}
int gstr_replaceOneSub(gstrv_t dst, gstrc_t raw_sub, gstrc_t new_sub, int pos)
{
  char *src_p = dst->buff;
  uint len = gstr_len(dst);
  if (pos < 0 || pos > len)
  {
    return NO_FIND;
  }
  else
  {
    uint i = pos + 1;
    uint sub_len = raw_sub->cap_size;
    while ((i = gstr_findStrFrom(dst, i, raw_sub->buff)) != NO_FIND)
    {
      memcpy(src_p + i, new_sub, sub_len);
    }
    return 0;
  }
}
int gstr_replaceAllSub(gstrv_t dst, gstrc_t raw_sub, gstrc_t new_sub)
{
  char *src_p = dst->buff;
  uint i = 0;
  uint sub_len = raw_sub->cap_size;
  while ((i = gstr_findStrFrom(dst, i, raw_sub->buff)) != NO_FIND)
  {
    memcpy(src_p + i, new_sub, sub_len);
  }
  return 0;
}
int gstr_removeSpPos(gstrv_t dst, int pos)
{
  char *src_p = dst->buff;
  uint len = gstr_len(dst);
  if (pos < 0 || pos > len)
  {
    return NO_FIND;
  }
  else
  {
    uint i = pos;
    gstrv_t temp = gstr_new();
    while (*(src_p + i) != ' ')
    {
      gstr_appendChr(dst, *(src_p + i));
    }
    gstr_destroy(dst);
    dst = temp;
    return 0;
  }
}
int gstr_removeSp(gstrv_t dst)
{
  char *src_p = dst->buff;
  uint i = 0;
  gstrv_t temp = gstr_new();
  while (*(src_p + i) != ' ')
  {
    gstr_appendChr(temp, *(src_p + i));
  }
  gstr_destroy(dst);
  dst = temp;
  return 0;
}