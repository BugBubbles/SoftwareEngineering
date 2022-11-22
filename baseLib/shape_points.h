/*by梁耀星，点列表库，存放目标数据的全部点信息，用于直接绘图*/
#ifndef _SHAPE_POINTS_
#define _SHAPE_POINTS_

#ifdef __cplusplus
extern "C"
{
#endif
void circ_point_list(p_circ_c circ, float *list_x, float *list_y);
void line_point_list(p_line_c line, float* list_x, float* list_y);
void rect_point_list(p_rect_c rect, float *list_x, float *list_y);
void poly_point_list(p_poly_c poly, float *list_x, float *list_y);







#ifdef __cplusplus
}
#endif


#endif
