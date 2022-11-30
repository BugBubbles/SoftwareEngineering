#ifndef STRING_WRAPPER
#define STRING_WRAPPER
#ifdef __cplusplus
extern "C"
{
#endif // __cplusplus
  // interface data type
  struct GSTR;
  typedef struct GSTR *PGSTRV;       // pointers only
  typedef const struct GSTR *PGSTRC; // pointers only
  // constructor/destructor
  /*initialize an empty gstr
  Input:
    none
  Output:
    PGSTRV : a variable GSTR pointer, pointing to this empty gstr.\
    when execuation is failed return 0.
  */
  PGSTRV NewGSTR_Empty();
  /*initialize a new gstr from a string of characters.
  Input:
    const char *src : the pointer pointing to source string.
  Output:
    PGSTRV : a variable GSTR pointer, pointing to this new gstr.
    when execuation is failed return 0.
  */
  PGSTRV NewGSTR_ByStr(const char *src);
  /*initialize a customized blank space of memory.
  Input:
    int size : the byte size of expected memory space.
  Output:
    PGSTRV : a variable GSTR pointer, pointing to this empty gstr.
    when execuation is failed return 0.
  */
  PGSTRV NewGSTR_Blank(int size);
  /*destroy an existed pstr.
  Input:
    PGSTRV pthis : the pointer pointing to an existed pstr.
  Output:
    none.
  */
  void GSTRDestroy(PGSTRV pthis);
  /*instantiate an existed gstr from a character string.
  Input:
    PGSTRV pthis : the pointer pointing to an existed pstr.
    const char *src : the pointer pointing to source string.
  Output:
    none.
  */
  void GSTRImport(PGSTRV pthis, const char *src);
  /*export the gstr to overwrite a specific character string.
  Input:
    PGSTRC pthis : the read-only pointer pointing to an existed pstr.
    const char *dst : the pointer pointing to destination string.
  Output:
    none.
  */
  void GSTRExport(PGSTRC pthis, char *dst);
  // read
  /*acquire the length of certain gstr.
  Input:
    PGSTRC pthis : the read-only pointer pointing to an existed pstr.
  Output:
    int : the length of gstr.
  */
  int GSTRLen(PGSTRC s);
  /*compare the order of two specific gstr in dictionary order.
  Input:
    PGSTRC a : the read-only pointer pointing to an existed pstr.
    PGSTRC b : the read-only pointer pointing to another existed pstr.
  Output:
    int : the result,which only can be 0, 1 and -1.
    0 : the two gstr are equal in order.
    1 : the gstr a is prior to b.
    -1 : the gstr a is suprior to b.
  */
  int GSTRCmp(PGSTRC a, PGSTRC b);
  /*find the specified character in a gstr.
  Input:
    PGSTRC s : the read-only pointer pointing to an existed pstr.
    char c : the specified character.
  Output:
    int : if c is really existed in gstr, return its location index,
    or return -1 when c is not existed.
  */
  int GSTRFindChr(PGSTRC s, char c);
  /*find the specified character string in a gstr.
  Input:
    PGSTRC s : the read-only pointer pointing to an existed pstr.
    char *sub : a pointer pointing to the specified character string.
  Output:
    int : if sub is really existed in gstr, return its location index,
    or return -1 when sub is not existed.
  */
  int GSTRFindStr(PGSTRC s, const char *sub);
  // write
  /*copy one gstr to another.
  Input:
    PGSTRV d : the destination gstr.
    PGSTRC s : the source gstr.
  Output:
    none.
  */
  void GSTRCpy(PGSTRV d, PGSTRC s);
  /*concat two gstrs to a entire one.
  Input:
    PGSTRV d : the former gstr, as well as the destination gstr.
    PGSTRC s : the latter gstr.
  Output:
    none.
  */
  void GSTRCat(PGSTRV d, PGSTRC s);
  /*insert one gstr to another gstr.
  Input:
    PGSTRV d : the gstr to accomodate inserted one, as well as the destination gstr.
    PGSTRC s : the gstr to insert.
    int pos : the insert location in gstr d.
  Output:
    none.
  */
  void GSTRIns(PGSTRV d, PGSTRC s, int pos);
  /*clip certain length part of gstr.
  Input:
    PGSTRV d : the gstr to be clipped.
    int len : the beginning location index in d.
    int pos : the length of clipped part.
  Output:
    none.
  */
  void GSTRDel(PGSTRV d, int pos, int len);
  //返回对应位置的元素
  char GSTRInd(PGSTRV d, int pos);
  //提取子列的函数
  // src：源gstr；begin：起始索引，从0开始；end：终止索引，
  //对应位置即为子列最后一个元素在原序列上的位置，最大为len-1；
  PGSTRV GSTRSubStr(PGSTRC src, int begin, int end);
#ifdef __cplusplus
}
#endif // __cplusplus

#endif // !STRING_WRAPPER
