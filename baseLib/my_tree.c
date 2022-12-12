#include "my_tree.h"
#include "general_list.h"
#include "malloc.h"
#include "string.h"
typedef unsigned int nodedata_t;
typedef glstv_t branches_t;
typedef struct _tree_
{
  nodedata_t nodedata;
  branches_t nextnodes;
  int is_leaf; // 表示是否是树叶，是为1，不是为0
} _tree_;

// 新建空树
treev_t tree_new()
{
  treev_t tree = (treev_t)malloc(sizeof(_tree_));
  tree->nodedata = NULL;
  tree->nextnodes = glst_new(sizeof(int));
  tree->is_leaf = 1;
}
//递归删除结点，用时较多。
void tree_destroy(treev_t tree)
{
  if (tree->is_leaf)
  {
    free(tree->nodedata);
    return;
  }
  int i;
  glstv_t temp = glst_new(sizeof(int));
  glst_assign(temp, tree->nextnodes);
  for (i = 0; i < glst_len(tree->nextnodes); i++)
  {
    treenodev_t treenode=(treenodev_t)malloc(sizeof(int));
    glst_getnode(temp,i,treenode);
    tree_destroy(treenode);
    free(treenode);
  }
  glst_destroy(temp);
}
