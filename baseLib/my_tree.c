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
} _tree_;

// 新建空树
treev_t tree_new()
{
  treev_t tree = (treev_t)malloc(sizeof(_tree_));
  tree->nodedata = NULL;
  tree->nextnodes = glst_new(sizeof(int));
}
