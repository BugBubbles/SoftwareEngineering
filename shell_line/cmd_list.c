#include "cmd_list.h"
#include "malloc.h"
#include "my_basedshapes.h"
// 新建一个标准化命令行列表
std_cmdlist_t std_cmdline_list_new()
{
  // 新建一个glist存放标准化命令行列表
  // 表内每一个元素都是一个标准化命令
  glstv_t std_cmdlist = glst_new(std_cmdline_size());
  // 返回这个新建的表
  return std_cmdlist;
}
// 删除一个标准化命令行列表
void std_cmdline_list_del(std_cmdlist_t std_cmdlist)
{
  glst_destroy(std_cmdlist);
}
// 向命令行列表中添加新的标准化命令
void std_cmdlist_append(std_cmdlist_t std_cmdlist, std_cmdlinec_t std_cmdline)
{
  glst_appendNode(std_cmdlist, std_cmdline);
}
// 获取命令行列表长度
int std_cmdlist_length(std_cmdlist_t std_cmdlist)
{
  glst_len(std_cmdlist);
}
// 获取命令行列表某一行的命令
std_cmdlinev_t std_cmdlist_getline(std_cmdlist_t std_cmdlist, int pos)
{
  // 问一下博非大哥
  // 这个是用来从命令的列表中获取第i行的命令的
  cmdtype_t temp_cmdtype = _NONE;
  int temp_paranum = 2;

  std_cmdlinev_t temp_cmdline = std_cmdline_new(temp_cmdtype, temp_paranum);
  // 复制了对应命令行命令
  glst_getnode(std_cmdlist, pos, temp_cmdline);
  return temp_cmdline;
}
