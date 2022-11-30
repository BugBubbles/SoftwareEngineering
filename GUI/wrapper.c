#include "wrapper.h"
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#ifdef WIN32
#pragma warning(disable : 4996)
#endif // WIN32
#ifndef SAME
#define LONGER_BUT_LATTER 4
#define LONGER_AND_SAME 3
#define LONGER_BUT_FOREM 2
#define LATTER 1
#define SAME 0
#define FOREM -1
#define SHORTER_BUT_LATTER -2
#define SHORTER_AND_SAME -3
#define SHORTER_BUT_FOREM -4
#endif
typedef struct GSTR
{
  int length;
  char *data;
} GSTR;
PGSTRV NewGSTR_Empty()
{
  PGSTRV obj = (PGSTRV)malloc(sizeof(GSTR));
  if (obj)
  {
    obj->data = 0;
    obj->length = 0;
    return obj;
  }
  return 0; // failed
}
PGSTRV NewGSTR_ByStr(const char *src)
{
  PGSTRV obj = NewGSTR_Empty();
  if (obj)
  {
    GSTRImport(obj, src);
    return obj;
  }
  return 0; // failed
}
PGSTRV NewGSTR_Blank(int size)
{
  PGSTRV obj = (PGSTRV)malloc(sizeof(GSTR));
  if (obj)
  {
    // try to allocate buffer
    obj->data = (char *)calloc(1, size + 1);
    if (obj->data)
    {
      // allocate successful
      obj->length = size;
      return obj;
    }
    else
    {
      free(obj);
      return 0;
    }
  }
  return 0; // failed
}
void GSTRDestroy(PGSTRV pthis)
{
  if (pthis->data)
  {
    free(pthis->data);
    pthis->length = 0;
  }
  free(pthis);
}
void GSTRImport(PGSTRV pthis, const char *src)
{
#ifdef _DEBUG
  assert(pthis);
  assert(src);
#endif // _DEBUG
  int n = strlen(src);
  if (pthis->data)
  {
    free(pthis->data); // not null now,
    pthis->data = 0;
  }
  pthis->data = (char *)calloc(1, n + 1);
  pthis->length = n;
  if (pthis->data)
  {
    memcpy(pthis->data, src, n);
  }
}
void GSTRExport(PGSTRC pthis, char *dst) //需要多一步把末尾置为\0
{
#ifdef _DEBUG
  assert(pthis);
  assert(dst);
#endif // _DEBUG
  memcpy(dst, pthis->data, pthis->length);
}
// read
int GSTRLen(PGSTRC s)
{
  return s->length;
}

int GSTRCmp(PGSTRC a, PGSTRC b) //比较不全面，还需要比较length，再使用memcmp比较内存数据
{
  int result;
  if (a->length > b->length)
  {
    result = memcmp(a->data, b->data, b->length * sizeof(char));
    return LONGER_AND_SAME + result;
  }
  else if (a->length < b->length)
  {
    result = memcmp(a->data, b->data, a->length * sizeof(char));
    return SHORTER_AND_SAME + result;
  }
  else
  {
    return memcmp(a->data, b->data,a->length*sizeof(char));
  }
}
int GSTRFindChr(PGSTRC s, char c)
{
  char *pos = strchr(s->data, c);
  if (pos)
  {
    return pos - s->data;
  }
  else
  {
    return -1;
  }
}
int GSTRFindStr(PGSTRC s, const char *sub)
{
#ifdef _DEBUG
  assert(s && (s->data) && (sub));
#endif // _DEBUG
  char *pos = strstr(s->data, sub);
  if (pos)
  {
    return pos - s->data;
  }
  else
  {
    return -1;
  }
}
// write
void GSTRCpy(PGSTRV d, PGSTRC s)
{
#ifdef _DEBUG
  assert(s && (s->data) && d);
#endif // _DEBUG
  if (d->data)
  {
    free(d->data);
    d->data = 0;
  }
  d->length = s->length;
  d->data = (char *)calloc(1, d->length);
  if (d->data)
  {
    memcpy(d->data, s->data, d->length);
  }
}
void GSTRCat(PGSTRV d, PGSTRC s)
{
#ifdef _DEBUG
  assert(s && (s->data) && d);
#endif // _DEBUG
  if (d->data)
  {
    int len = s->length + d->length + 1;
    char *tmp = (char *)calloc(1, len);
    if (tmp)
    {
      strcpy(tmp, d->data);
      strcat(tmp, s->data);
      free(d->data);
      d->data = tmp;
      d->length = len;
    }
  }
  else
  { // d data empty
    GSTRCpy(d, s);
  }
}
void GSTRIns(PGSTRV d, PGSTRC s, int pos)
{
#ifdef _DEBUG
  assert(s && (s->data) && d && (d->data));
#endif // _DEBUG
  char *tmp = (char *)calloc(1, 1 + s->length + d->length);
  if (tmp)
  {
    strncpy(tmp, d->data, pos); //[0,...d_pos-1] [s0,...s[m-1]]
    strcat(tmp, s->data);
    strcat(tmp, d->data + pos);
    free(d->data);
    d->data = tmp;
    d->length = s->length + d->length;
  }
}
void GSTRDel(PGSTRV d, int pos, int len)
{
#ifdef _DEBUG
  assert(d && (d->data) && (pos >= 0) && (len >= 0));
#endif // _DEBUG
  char *tmp = (char *)calloc(1, 1 + d->length - len);
  if (tmp)
  {
    strncpy(tmp, d->data, pos); // bugs are possible
    strcpy(tmp, d->data + pos + len);
    free(d->data);
    d->data = tmp;
    d->length -= len;
  }
}
char GSTRInd(PGSTRV d, int pos)
{
  if (pos >= 0 && pos < d->length)
  {
    return *(d->data + pos);
  }
  else
  {
    printf("error!The index is out of range!");
    return '\0';
  }
}

PGSTRV GSTRSubStr(PGSTRC src, int begin, int end)
{
  if (begin >= 0 && end < src->length)
  {
    int len = end - begin + 1;
    char *temp = (char *)calloc(len, sizeof(char));
    memcpy(temp, src->data + begin, len * sizeof(char));
    PGSTRV gstr_temp = NewGSTR_ByStr(temp);
    free(temp);
    return gstr_temp;
  }
  else
  {
    printf("Error!The index of the sub-string is invalid!");
    return NULL;
  }
}