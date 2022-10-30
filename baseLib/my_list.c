#include <stdlib.h>
#include "my_ctype.h"
#include <malloc.h>
#include <assert.h>
#include "my_list.h"
#include <stdio.h>
#ifndef NULL
#define NULL ((void *)0)
#endif
#define _IS_EMPTY_ 1
#define _NOT_EMPTY_ 0

void node_free_innate(node_data *node)
{
  free(node->next);
  free(node);
}
node_data *list_new()
{
  node_data *temp = (node_data *)malloc(sizeof(node_data));
  temp->next = NULL;
  temp->val = NULL;
  return temp;
}
node_data *list_new_val(void *val)
{
  node_data *temp = (node_data *)malloc(sizeof(node_data));
  temp->next = NULL;
  temp->val = val;
  return temp;
}
node_data *list_cat(node_data *data_list, void *data_next)
{
  assert(data_list != NULL);
  node_data *temp = (node_data *)malloc(sizeof(node_data));
  temp->val = data_next;
  temp->next = data_list;
  return temp;
}
node_data *list_que(node_data *data_list, void *data_next)
{
  assert(data_list != NULL);
  if (data_list->next != NULL)
  {
    printf("ERROR!CANNOT insert quene item into stack!");
    return NULL;
  }
  node_data *temp = (node_data *)malloc(sizeof(node_data));
  temp->val = data_next;
  data_list->next = temp;
  return temp;
}
void list_out(node_data *data_list, void *out_val)
{
  assert(data_list != NULL);
  out_val = data_list->val;
  free(data_list);
}

void list_del_innate(node_data *data_list)
{
  assert(data_list != NULL);
  node_data *temp = (node_data *)malloc(sizeof(node_data));
  temp = NULL;
  while (data_list->next != NULL)
  {
    temp = data_list->next;
    free(data_list);
    data_list = temp;
  }
  free(data_list->next);
  data_list = NULL;
  free(data_list);
}
void list_del_usr(node_data *data_list)
{
  assert(data_list != NULL);
  node_data *temp = (node_data *)malloc(sizeof(node_data));
  temp = NULL;
  while (data_list->next != NULL)
  {
    free(data_list->val);
    temp = data_list->next;
    free(data_list);
    data_list = temp;
  }
  free(data_list->val);
  free(data_list->next);
  free(data_list);
}
uint list_len(node_data *data_list)
{
  assert(data_list != NULL);
  uint iter = 0;
  node_data *temp = (node_data *)malloc(sizeof(node_data));
  temp = data_list;
  if (temp == NULL)
  {
    return 0;
  }
  while (temp->next != NULL)
  {
    iter++;
    temp = temp->next;
  }
  temp = NULL;
  free(temp);
  return iter;
}
uint list_emp(const node_data *data_list)
{
  assert(data_list != NULL);
  if (data_list->next == NULL)
  {
    return _IS_EMPTY_;
  }
  else
  {
    return _NOT_EMPTY_;
  }
}
node_data *list_inv_cpy(node_data *data_list)
{
  assert(data_list != NULL);
  node_data *temp = list_new();
  while (data_list->next != NULL)
  {
    temp = list_cat(temp, data_list->val);
    data_list = data_list->next;
  }
  return temp;
}
node_data *list_inv(node_data *data_list)
{
  assert(data_list != NULL);
  node_data *temp = list_new();
  while (data_list->next != NULL)
  {
    temp = list_cat(temp, data_list->val);
    data_list = data_list->next;
  }
  list_del_innate(data_list);
  return temp;
}
void *memcpy(void *dest, const void *src, size_t count)
{
  assert(dest != NULL && src != NULL);

  char *p = (char *)dest;
  char *q = (char *)src;
  if (p == q)
    return p;

  while (count--)
  {
    *p++ = *q++;
  }

  return dest;
}
node_data *list_cpy(node_data *data_list)
{
  assert(data_list != NULL);
  node_data *temp1 = list_inv_cpy(data_list);
  return list_inv_cpy(temp1);
}

void list_prt(node_data *data_list, void **buff)
{
  assert(data_list != NULL && buff != NULL);
  uint i = 0;
  node_data *temp = (node_data *)malloc(sizeof(node_data));
  temp = list_inv_cpy(data_list);
  node_data *stor = (node_data *)malloc(sizeof(node_data));
  stor = temp;
  while (temp->next != NULL)
  {
    *(buff + i) = (temp->val);
    temp = temp->next;
    i++;
  }
  list_del_innate(temp);
  list_del_innate(stor);
}

void **list_ind(node_data *data_list, uint ind)
{
  assert(data_list != NULL);
  uint iter = 0;
  void **temp = (void **)malloc(sizeof(void *));
  node_data *data_inv = list_inv_cpy(data_list);
  while (iter != ind)
  {
    if (data_inv->next != NULL)
    {
      data_inv = data_inv->next;
    }
    else
    {
      break;
    }
    iter++;
  }
  if (iter < ind)
  {
    return NULL;
  }
  *temp = data_inv->val;
  list_del_innate(data_inv);
  return temp;
}
void **list_nod(node_data *node)
{
  assert(node != NULL);
  void **temp = (void **)malloc(sizeof(void *));
  *temp = node->val;
  return temp;
}
node_data *list_sub(node_data *data_list, uint ind, uint len)
{
  assert(data_list != NULL);
  node_data *data_temp = list_inv_cpy(data_list);
  node_data *temp = list_new();
  uint iter = 0;
  while (iter < ind)
  {
    if (data_temp->next == NULL)
    {
      list_del_innate(data_temp);
      list_del_innate(temp);
      return NULL;
    }
    data_temp = data_temp->next;
    iter++;
  }
  iter = 0;
  while (iter < len)
  {
    if (data_temp->next == NULL)
    {
      list_del_innate(data_temp);
      return list_inv_cpy(temp);
    }
    temp = list_cat(temp, data_temp->val);
    data_temp = data_temp->next;
    iter++;
  }
  list_del_innate(data_temp);
  return list_inv_cpy(temp);
}
int int_from_char_list(node_data *data_list)
{
  assert(data_list != NULL);
  int temp = 0, sign = 1;
  node_data *temp_list = (node_data *)malloc(sizeof(node_data));
  temp_list = data_list;
  char temp_char = *(char *)temp_list->val;
  if (temp_char == '-')
  {
    sign = -1;
    temp_list = temp_list->next;
  }
  do
  {
    if (is_number(*(char *)temp_list->val))
    {
      temp = temp * 10 + *(char *)temp_list->val - '0';
      temp_list = temp_list->next;
    }
    else
    {
      printf("\n----------------****----------------\nERROR!\nThere are INVALID characters in DECIMAL number.\nPlease check your input or COMFIRM the type of list value is CHAR!\n----------------****----------------\n");
      temp_list = NULL;
      free(temp_list);
      return 0;
    }
  } while (temp_list->next != NULL);
  temp_list = NULL;
  free(temp_list);
  return temp * sign;
}
float float_from_char_list(node_data *data_list)
{
  assert(data_list != NULL);
  float temp_int = 0, temp_dec = 0, sign = 1.0;
  node_data *temp_list = (node_data *)malloc(sizeof(node_data));
  node_data *fract_list = list_new();
  temp_list = data_list;
  char temp_char = *(char *)temp_list->val;
  if (temp_char == '-')
  {
    sign = -1.0;
    temp_list = temp_list->next;
  }
  //整数部分
  while (temp_list->next != NULL)
  {
    if (*(char *)(temp_list->val) == '.')
    {
      temp_list = temp_list->next;
      fract_list = list_inv_cpy(temp_list);
      break;
    }
    else if (is_number(*(char *)temp_list->val))
    {
      temp_int = temp_int * 10 + *(char *)temp_list->val - '0';
      temp_list = temp_list->next;
    }
    else
    {
      printf("\n----------------****----------------\nERROR!\nThere are INVALID characters in DECIMAL number.\nPlease check your input or COMFIRM the type of list value is CHAR!\n----------------****----------------\n");
      temp_list = NULL;
      free(temp_list);
      return 0.0;
    }
  }
  //小数部分
  while (fract_list->next != NULL)
  {
    if (is_number(*(char *)fract_list->val))
    {
      temp_dec = (temp_dec + *(char *)fract_list->val - '0') * 0.1;
      fract_list = fract_list->next;
    }
    else
    {
      printf("\n----------------****----------------\nERROR!\nThere are INVALID characters in DECIMAL number.\nPlease check your input or COMFIRM the type of list value is CHAR!\n----------------****----------------\n");
      list_del_innate(fract_list);
      return 0.0;
    }
  }
  temp_list = NULL;
  free(temp_list);
  list_del_innate(fract_list);
  return (temp_int + temp_dec) * sign;
}

/*以下为专用函数了*/
