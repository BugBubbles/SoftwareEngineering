#include "transform.h"
#include "my_ctype.h"
// 第一步转换，把txt里面某一行命令string，转化为标准命令序列std_cmdline_t
// 要求：实现参数提取，命令类型提取，错误命令返回空命令并报错，多余的空格 和制表符 去除
std_cmdlinev_t transform_txtline_cmdline(gstrc_t cmdline)
{
  gstrv_t cmdname = gstr_new();
  std_cmdlinev_t std_cmdline = std_cmdline_new();
  // 首先一直查找直到遇到左括号，把这部分去除空格以后变成命令名。
  int cmd = gstr_findChr(cmdline, '(');
  gstr_getSub_byPos(cmdline, cmdname, 0, cmd);
  gstr_removeSp(cmdname);
  // cmdname里面装得就是命令名
  cmdtype_t cmdtype = str_to_cmdtype(cmdname);
  gstr_destroy(cmdname);
  std_cmdline_set_type(std_cmdline, cmdtype);
  // 然后提取括号里面的东西，并检查括号是否匹配，取得参数的名称与值，编写名称、值的转化程序。
  int len = gstr_len(cmdline), paranum = 0;
  gstrv_t cmdpara = gstr_new();
  gstr_getSub_byPos(cmdline, cmdpara, cmd + 1, len - 1);
  gstr_removeSp(cmdpara);
  // 首先输入一个字符串，输出一个参数序列，参数类型序列和参数个数，返回值是判定是否有效的int值
  str_to_para(cmdpara, std_cmdline, &paranum);
  return std_cmdline;
}
// 第一步转换，把txt里面的全部行命令string，转化为一串标准命令序列
std_cmdlist_t transform_txtcmd_cmdlist(gstrc_t txtcmd)
{
  std_cmdlist_t std_cmdlist = std_cmdline_list_new();
  gstrv_t head = gstr_new();
  char END[4] = {'e', 'n', 'd'};
  std_cmdlinev_t std_cmdline;
  int begin = 0, end = gstr_findChr(txtcmd, '\n');
  do
  {
    gstr_getSub_byPos(txtcmd, head, begin, end);
    gstr_removeSp(head);
    std_cmdline = transform_txtline_cmdline(head);
    glst_appendNode(std_cmdlist, std_cmdline);
  } while (gstr_cmp_byStr(head, END) != 0);
  return std_cmdlist;
}
// 第二步转换，把标准命令序列，转化为图像
graph_t transform_cmdlist_graph(std_cmdlist_t cmdlist)
{
  graph_t graph = graph_new();
  std_cmdlinev_t cmdline;
  supershape_t supershape;
  int i = 0, len = glst_len(cmdlist);
  while (i < len)
  {
    glst_getnode(cmdlist, i, cmdline);
    // switch (cmdline)
    // {
    // case /* constant-expression */:
    //   /* code */
    //   break;

    // default:
    //   break;
    // }
    // supershape =
    i++;
  }

  // graph_new() for (i = 0->batcmd_lenght() - 1)
  // {
  //   batcmd_getcmdline()->cmdline switch (cmdline_getcmdtype())
  //   {
  //   case _LINE:
  //   graph_addshape() case _CIRC:
  //   case _MOVE:
  //   }
  // }
}
void transform_txtline_cmdline_line(gstrc_t line)
{
}
cmdtype_t str_to_cmdtype(gstrc_t cmdname)
{
  char line[5] = {'l', 'i', 'n', 'e'},
       circ[5] = {'c', 'i', 'r', 'c'},
       rect[5] = {'r', 'e', 'c', 't'},
       poly[5] = {'p', 'o', 'l', 'y'},
       trans[6] = {'t', 'r', 'a', 'n', 's'},
       group[6] = {'g', 'r', 'o', 'u', 'p'};
  if (gstr_cmp_byStr(cmdname, line) == 0 || gstr_cmp_byStr(cmdname, circ) == 0 || gstr_cmp_byStr(cmdname, rect) == 0 || gstr_cmp_byStr(cmdname, poly) == 0)
  {
    return _NEW;
  }
  else if (gstr_cmp_byStr(cmdname, group) == 0)
  {
    return _GROUP;
  }
  else if (gstr_cmp_byStr(cmdname, trans) == 0)
  {
    return _MODIFY;
  }
  else
  {
    return _NONE;
  }
}
paratype_t str_to_paratype(gstrc_t paraname)
{
  char handle[7] = {'h', 'a', 'n', 'd', 'l', 'e'},
       center[7] = {'c', 'e', 'n', 't', 'e', 'r'},
       radius[7] = {'r', 'a', 'd', 'i', 'u', 's'},
       diameter[9] = {'d', 'i', 'a', 'm', 'e', 't', 'e', 'r'},
       angle[6] = {'a', 'n', 'g', 'l', 'e'},
       length[7] = {'l', 'e', 'n', 'g', 't', 'h'},
       point[6] = {'p', 'o', 'i', 'n', 't'},
       vector[7] = {'v', 'e', 'c', 't', 'o', 'r'};
  if (gstr_cmp_byStr(paraname, handle) == 0)
  {
    return _HANDLE;
  }
  else if (gstr_cmp_byStr(paraname, center) == 0)
  {
    return _CENTER;
  }
  else if (gstr_cmp_byStr(paraname, point) == 0)
  {
    return _POINT;
  }
  else if (gstr_cmp_byStr(paraname, radius) == 0)
  {
    return _RADIUS;
  }
  else if (gstr_cmp_byStr(paraname, angle) == 0)
  {
    return _ANGLE;
  }
  else if (gstr_cmp_byStr(paraname, length) == 0)
  {
    return _LENGTH;
  }
  else if (gstr_cmp_byStr(paraname, diameter) == 0)
  {
    return _DIAMETER;
  }
  else
  {
    return _ERROR;
  }
}
int str_to_para(gstrc_t str_para, std_cmdlinev_t std_cmdline, int *paranum)
{
  // 判断括号、引号闭合
  int pos = 0;
  int len = gstr_len(str_para);
  int brac_index = 0, pomma_index = 0;
  while (pos < len)
  {
    if (gstr_getChr(str_para, pos) == '(')
    {
      brac_index++;
    }
    else if (gstr_getChr(str_para, pos) == '\'' && is_alpha(gstr_getChr(str_para, pos + 1)) == 1)
    {
      // 右边是字母的引号，增加计数标记
      pomma_index++;
    }
    else if (gstr_getChr(str_para, pos) == '\'' && is_alpha(gstr_getChr(str_para, pos - 1)) == 1)
    {
      // 左边是字母的引号，减少计数标记
      pomma_index--;
    }
    else if (gstr_getChr(str_para, pos) == ')')
    {
      brac_index--;
    }
    else
    {
    }
    pos++;
  }
  if (brac_index != 0 || pomma_index != 0)
  {
    return 1; // 引号或者括号不匹配，异常退出
  }
  else
  {
    brac_index = 0;
    pomma_index = 0;
    int number_index = 0;
    paratype_t paratype;
    float para_1, para_2;
    for (pos = 0; pos < len;)
    {
      if (gstr_getChr(str_para, pos) == '\'' && pomma_index == 0) // 取得参数名
      {
        pomma_index = pos;
      }
      else if (gstr_getChr(str_para, pos) == '\'' && pomma_index != 0)
      {
        gstrv_t temp = gstr_new_bySize(pos - pomma_index + 1);
        gstr_getSub_byPos(str_para, temp, brac_index, pos);
        paratype = str_to_paratype(temp);
        gstr_destroy(temp);
        pomma_index = 0;
        *paranum = *paranum + 1;
      }
      else if (gstr_getChr(str_para, pos) == '(' && gstr_getChr(str_para, pos - 1) == ':')
      {
        brac_index = pos;
      }
      else if (gstr_getChr(str_para, pos) == ',' && brac_index != 0) // 得到的是向量或者点的x值
      {
        gstrv_t temp = gstr_new_bySize(pos - brac_index + 1);
        gstr_getSub_byPos(str_para, temp, brac_index, pos); // 得到的是向量或者点的x值gstr
        if (~gstr_strToNum(&para_1, temp))
        {
          brac_index = pos;
          gstr_destroy(temp);
        }
        else
        {
          gstr_destroy(temp);
          return -1; // 返回值不为0，则出错了
        }
      }
      else if (gstr_getChr(str_para, pos) == ')' && brac_index != 0) // 得到的是向量或者点的y值
      {
        gstrv_t temp = gstr_new_bySize(pos - brac_index + 1);
        gstr_getSub_byPos(str_para, temp, brac_index, pos); // 得到的是向量或者点的y值gstr
        if (~gstr_strToNum(&para_2, temp))
        {
          brac_index = 0;
          gstr_destroy(temp);
          std_cmdline_add_para(std_cmdline, paratype, para_1, para_2);
        }
        else
        {
          gstr_destroy(temp);
          return -1; // 返回值不为0，则出错了
        }
      }
      else if (is_number(gstr_getChr(str_para, pos)) == 1 && gstr_getChr(str_para, pos + 1) == ':')
      {
        number_index = pos;
        pos = gstr_skipSpFindChr(str_para, pos, ')');
        int temp_pos = gstr_skipSpFindChr(str_para, pos, ',');
        pos = (temp_pos < pos && temp_pos != -1) ? temp_pos : pos;
        gstrv_t temp = gstr_new_bySize(pos - number_index + 1);
        gstr_getSub_byPos(str_para, temp, number_index, pos); // 得到的是向量或者点的x值gstr
        if (~gstr_strToNum(&para_1, temp))
        {
          std_cmdline_add_para(std_cmdline, paratype, para_1, para_2);
          gstr_destroy(temp);
        }
        else
        {
          gstr_destroy(temp);
          return -1; // 返回值不为0，则出错了
        }
      }
    }
    return 0;
  }
}