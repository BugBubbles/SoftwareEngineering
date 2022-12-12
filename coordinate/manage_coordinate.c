#include "manage_coordinate.h"
#include "general_list.h"
#include "malloc.h"
#include "handle.h"

typedef struct _coor_manager_
{
  coordinatev_t coor_above;
  glstv_t coors_below;
  coordinatev_t coor;
} _coor_manager_;
// 存储manage的线性表
static glstv_t coor_manager;
// 存储坐标系handle的线性表
// static glstv_t coor_manager_handle;
coor_manager_t new_register()
{
  coor_manager_t coor_register = (coor_manager_t)malloc(sizeof(_coor_manager_));
  coor_register->coor_above = NULL;
  coor_register->coors_below = NULL;
  return coor_register;
}
coordinatev_t get_above_coor(coordinatev_t coor)
{
  int index = glst_findNode(coor_manager, coor);
  coor_manager_t coor_register = new_register();
  glst_getnode(coor_manager, index, coor_register);
  coordinatev_t temp = coor_register->coor_above;
  free(coor_register);
  return temp;
}
glstv_t get_below_coor(coordinatev_t coor)
{
  int index = glst_findNode(coor_manager, coor);
  coor_manager_t coor_register = new_register();
  glst_getnode(coor_manager, index, coor_register);
  glstv_t temp = coor_register->coors_below;
  free(coor_register);
  return temp;
}
void new_coor_manager(coordinatec_t top_coor)
{
  coor_manager_t coor_register = new_register();
  coor_manager = glst_new(sizeof(coor_manager_t));
  coor_register->coor = top_coor;
  coor_register->coor_above = NULL;
  coor_register->coors_below = glst_new(sizeof(coordinatec_t));
  glst_appendNode(coor_manager, coor_register);
}

coordinatev_t get_top()
{
  coor_manager_t top_coor_register = new_register();
  glst_getnode(coor_manager, 0, top_coor_register);
  coordinatev_t temp = top_coor_register->coor;
  free(top_coor_register);
  return temp;
}
void store_sub_coor(coordinatec_t above_coor, coordinatec_t coor)
{
  coor_manager_t coor_register = new_register();
  coor_register->coor = coor;
  coor_register->coor_above = above_coor;
  glst_appendNode(coor_manager, coor_register);
}
void destory_coor_manager(coordinatev_t coor)
{
  glstv_t coor_below = get_below_coor(coor);
  // 当它是最底层坐标系时
  if (coor_below == NULL)
  {
    int index = glst_findNode(coor_manager, coor);
    glst_deleteNode(coor_manager, index);
    destory_coor(coor);
    return;
  }
  else // 当它不是最底层坐标系时
  {
    int len = glst_len(coor_below);
    glstv_t temp_sub_list = glst_new_bySize(sizeof(coordinatev_t), len);
    glst_assign(temp_sub_list, coor_below);
    int i;
    for (i = 0; i < len; i++)
    {
      coordinatev_t temp_below = get_below_coor(coor);
      destory_coor_manager(temp_below);
      glst_deleteNode(coor_below, i);
    }
    glst_destroy(temp_sub_list);
    // 将原父坐标系降级为子坐标系
    int index = glst_findNode(coor_manager, coor);
    coor_manager_t coor_register = new_register();
    coor_register->coor_above = get_above_coor(coor);
    coor_register->coor = coor;
    glst_setnode(coor_manager, index, coor_register);
    free(coor_register);
  }
}
point_t relati_point_to_absol_point(coordinatec_t relati_coor, point_t relati_point)
{
  if (get_coor_is_top(relati_coor))
  {
    point_t temp;
    temp.x_val = relati_point.x_val;
    temp.y_val = relati_point.y_val;
    return temp;
  }
  point_t relati_base_point = get_coor_basepnt(relati_coor);
  float relati_base_point_x = relati_base_point.x_val;
  float relati_base_point_y = relati_base_point.y_val;
  relati_point.x_val += relati_base_point_x;
  relati_point.y_val += relati_base_point_y;
  return relati_point_to_absol_point(get_above_coor(relati_coor), relati_point);
}
ui_point_t math_point_to_ui_point(coordinatec_t math_coor, point_t math_point, ui_coordinate_t ui_coordinate)
{
  coordinatev_t top_coor = get_top();
  float temp_scale[4];
  point_t temp_absol_point = relati_point_to_absol_point(math_coor, math_point);
  get_coor_scale(top_coor,temp_scale);
  ui_point_t ui_point;
  ui_point.x_val = ui_coordinate.scale_x / (temp_scale[1] - temp_scale[0]) * math_point.x_val;
  ui_point.y_val = ui_coordinate.scale_y / (temp_scale[3] - temp_scale[2]) * math_point.y_val;
  return ui_point;
}