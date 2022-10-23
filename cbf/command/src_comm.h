/*
 *This file provides with functions to get command
 *from commandline or from a specific command file.
 *
 */
#include "wrapper.h"
#include <stdio.h>
#include <stdlib.h>
#if include _SRC_COMMAND_
#define _SRC_COMMAND_
#endif
// This lets the driver code override the image size if it needs to. Make sure
// you don't hard-code these values anywhere!
#ifndef SIZEX
#define SIZEX 512
#define SIZEY 512
#endif
/*---------------------------------------------------------------------------*/

/*
 * This struct contains one node of the linked list, which represents a single
 * command. It's field should include:
 *
 *  - name   : A char array of size 10 holding the command name.
 *
 *  - data   : An pointer to a dynamic node buffer, where stores all the input
 *            args including points coordinates, length and radius.
 *  - next   : A pointer to a struct of the same type, this is used for the
 *            linked list.
 *
 */
typedef struct cmd_node
{
  char name[10];
  data_buff *data;
  struct cmd_node *next;

} cmd_node;
/*
 * This struct contains a buffer for 2 dimension data, namely vector data.
 * It's field should include:
 *
 *  - x_val   : A integar value for its first dimension.
 *
 *  - y_val   : A integar value for its second dimension.
 *
 *  - next    : A pointer to next potential data structure, it could be
 *              a same one or not.
 *
 *
 */
typedef struct data_buff
{
  int x_val;
  int y_val;
  struct data_buff *next;
} data_buff;
/*
 * The enumerate class for commands, which includes four types now.
 * They are point, line, circle and polygon.
 */
typedef enum cmd_type
{
  NOT_CMD = 0,
  POINT = 1,
  LINE,
  CIRCLE,
  POLYGON,
} cmd_type;

cmd_node *new_cmd_node(char cmd[10], data_buff buf);

//从文件读取命令的，生成命令名和命令数据
cmd_node * load_cmd_file(char *filename);
//从键盘读取命令的
cmd_node * read_cmd_std();
//从命令名和命令数据生成特征点数据结构，包括一个
cmd_node *new_cmd_list_add(cmd_node *cmd_list, cmd_node *new_item);
//根据命令名，将其定义为枚举变量
cmd_type enum_cmd_name(char cmd[10]);
//删除一个已经连接好的命令列表
void del_cmd_list(cmd_node *cmd_list);
//新建一个命令列表
cmd_type enum_cmd_name(char cmd[10]);