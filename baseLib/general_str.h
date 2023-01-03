/*by李翔，通用线性表*/
#ifndef _GENERAL_STR_
#define _GENERAL_STR_
#ifndef NULL
#define NULL ((void *)0)
#endif
#ifndef _SIZE_T
#define _SIZE_T
typedef unsigned long long int _size_t;
#endif
#ifdef __cplusplus
extern "C"
{
#endif
#include "handle.h"
  // 接口数据类型
  struct _gstr_;                        // 不完全类型，无法直接定义变量
  typedef struct _gstr_ *gstrv_t;       // 变量指针
  typedef const struct _gstr_ *gstrc_t; // 常量指针
  // 构造/析构
  gstrv_t gstr_new();
  gstrv_t gstr_new_byCStr(const char *s);
  gstrv_t gstr_new_bySize(_size_t gstrsize);
  void gstr_destroy(gstrv_t s);
  // 导入/导出
  void gstr_import(gstrv_t this, const char *src);
  void gstr_export(gstrc_t this, char *dst);
  void gstr_import_byInt(gstrv_t this, int src);
  // 读操作
  int gstr_len(gstrc_t s);
  int gstr_cmp(gstrc_t a, gstrc_t b);
  // 返回第一个符合条件的位置
  int gstr_findChr(gstrc_t s, char c);
  int gstr_findStr(gstrc_t s, gstrc_t sub);
  // 写操作
  void gstr_assign(gstrv_t d, gstrc_t s);
  void gstr_appendStr(gstrv_t d, gstrc_t s);
  void gstr_appendChr(gstrv_t d, char c);
  void gstr_insertSub(gstrv_t d, gstrc_t s, int pos);
  void gstr_deleteSub(gstrv_t d, int pos, int len);
  // 单个字符存取
  void gstr_setChr(gstrc_t s, char c, int pos);
  char gstr_getChr(gstrc_t s, int pos);
  // 字符串存取
  void gstr_setSub(gstrc_t s, gstrc_t sub, int pos);
  void gstr_getSub_bySize(gstrc_t s, gstrc_t sub, int pos, _size_t size);
  void gstr_getSub_byPos(gstrc_t s, gstrc_t sub, int begin, int end);
  // 语法操作
  // 返回自pos位置以后的不是字符c的最近一个位置
  int gstr_skipChr(gstrc_t s, int pos, char c);
  // 返回自pos位置以后，不是pos位置的字符下一个位置
  int gstr_skipSpChr(gstrc_t s, int pos);
  // // 从gstr里面查找自pos位置以后的子串sub
  int gstr_findStrFrom(gstrc_t s, int pos, gstrc_t sub);
  // 从gstr里面查找自pos位置以后，排除空格的字符c
  int gstr_skipSpFindChr(gstrc_t s, int pos, char c);
  // 从gstr里面查找自pos位置以后的子串sub
  int gstr_skipSpFindStr(gstrc_t s, int pos, gstrc_t sub);
  // 从gstr里面查找并替换自pos位置以后的第一个字符c
  int gstr_replaceOneChr(gstrv_t dst, char raw_c, char new_c, int pos);
  // 从gstr里面查找并替换全部字符c
  int gstr_replaceAllChr(gstrv_t dst, char raw_c, char new_c);
  // 从gstr里面查找并替换自pos位置以后的第一个子gstr
  int gstr_replaceOneSub(gstrv_t dst, gstrc_t raw_sub, gstrc_t new_sub, int pos);
  // 从gstr里面查找并替换全部子gstr
  int gstr_replaceAllSub(gstrv_t dst, gstrc_t raw_sub, gstrc_t new_sub);
  // 从gstr里面查找并替换自pos以后的全部空格
  int gstr_removeSpPos(gstrv_t dst, int pos);
  // 从gstr里面查找并替换全部空格
  int gstr_removeSp(gstrv_t dst);
  // 将gstr转化为浮点数字，默认顺序为大端存储，即低地址存放的是高位数字
  int gstr_strToNum(float *dst, gstrv_t src);
#ifdef __cplusplus
}
#endif

#endif