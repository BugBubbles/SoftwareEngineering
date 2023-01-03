/*by牛泽坤，字符处理函数库*/
#ifndef _my_ctype_new_H_INCLUDE_
#define _my_ctype_new_H_INCLUDE_

/*
IsNumber用于判断字符是否为数字字符
input：字符c
output：是返回1，否返回0
*/
short is_number(char c);
/*
IsAlpha用于判断字符是否为字母字符
input：字符c
output：是返回1，否返回0
*/
short is_alpha(char c);
/*
IsAlandNum用于判断字符是否为数字字符和字母
input：字符c
output：是返回1，否返回0
*/
short is_alpha_and_num(char c);
/*
IsInvisible用于判断字符是否为不可见字符
input：字符c
output：是返回1，否返回0
*/
short is_invisible(char c);
/*
IsTable用于判断字符是否为制表符
input：字符c
output：是返回1，否返回0
*/
short is_table(char c);
/*
IsSpace用于判断字符是否为空格符
input：字符c
output：是返回1，否返回0
*/
short is_space(char c);
/*
IsUpper用于判断字符是否为大写字母字符
input：字符c
output：是返回1，否返回0
*/
short is_upper(char c);
/*
IsLower用于判断字符是否为小写字母字符
input：字符c
output：是返回1，否返回0
*/
short is_lower(char c);
/*
Upper2Lower用于将字母字符转换为大写
input：字符c
output：当输入是合法字母字符时返回对应大写，否则返回'\0'
*/
char upper_2_lower(char c);
/*
Lower2Upper用于将字母字符转换为小写
input：字符c
output：当输入是合法字母字符时返回对应小写，否则返回'\0'
*/

char lower_2_upper(char c);
// 将数字由char类型转化为short类型
short char_to_num(char c);
// 检查是否为命令合法字符
short is_valid_char(char c);
// 检查是否为常见符号,.:()
short is_common_ab(char c);
#endif