/*by李翔，通用线性表*/
#ifndef _GENERAL_STR_
#define _GENERAL_STR_

#ifdef __cplusplus
extern "C"
{
#endif
  typedef unsigned int size_t;
  // 接口数据类型
  struct _gstr_;                        // 不完全类型，无法直接定义变量
  typedef struct _gstr_ *gstrv_t;       // 变量指针
  typedef const struct _gstr_ *gstrc_t; // 常量指针
  // 构造/析构
  gstrv_t gstr_new(size_t _size);
  gstrv_t gstr_new_byCStr(const char *s);
  gstrv_t gstr_new_bySize(size_t _size, int size);
  void gstr_destroy(gstrv_t s);
  // 导入/导出
  void gstr_import(gstrv_t this, const char *src);
  void gstr_export(gstrc_t this, char *dst);
  // 读操作
  int gstr_len(gstrc_t s);
  int gstr_cmp(gstrc_t a, gstrc_t b);
  int gstr_findChr(gstrc_t s, char c);
  int gstr_findStr(gstrc_t s, const char *sub);
  // 写操作
  void gstr_assign(gstrv_t d, gstrc_t s);
  void gstr_append(gstrv_t d, gstrc_t s);
  void gstr_insertSub(gstrv_t d, gstrc_t s, int pos);
  void gstr_deleteSub(gstrv_t d, int pos, int len);
  // // 语法操作
  // int gstr_skipChr(gstrc_t s, int pos, char c);
  // int gstr_skipSpChr(gstrc_t s, int pos);
  // int gstr_findStrFrom(gstrc_t s, int pos, const char *sub);
  // int gstr_skipSpFindChr(gstrc_t s, int pos, char c);
  // int gstr_skipSpFindStr(gstrc_t s, int pos, const char *sub);
  // int gstr_replaceOne(gstrv_t d, gstrc_t from, gstrc_t to, int pos);
  // int gstr_replaceAll(gstrv_t d, gstrc_t from, gstrc_t to);
#ifdef __cplusplus
}
#endif

#endif