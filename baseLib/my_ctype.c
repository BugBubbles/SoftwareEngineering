/*by牛泽坤，字符处理函数库*/
#include "my_ctype.h"
short is_number(char c)
{
  char temp = c;
  return temp >= 48 && temp <= 57;
}

short is_alpha(char c)
{
  char temp = c;
  return (temp >= 65 && temp <= 90) || (temp >= 97 && temp <= 122);
}

short is_alpha_and_Num(char c)
{
  char temp = c;
  return is_number(temp) || is_alpha(temp);
}

short is_invisible(char c)
{
  char temp = c;
  return temp <= 20 || temp == 127;
}

short is_table(char c)
{
  char temp = c;
  return temp == 9 || temp == 11;
}

short is_space(char c)
{
  char temp = c;
  return temp == 32;
}

short is_upper(char c)
{
  char temp = c;
  return temp >= 90 && temp <= 122;
}

short is_lower(char c)
{
  char temp = c;
  return temp >= 65 && temp <= 90;
}
char upper_2_lower(char c)
{
  if (is_alpha)
  {
    return c - 32;
  }
  else
  {
    return '\0';
  }
}
char lower_2_upper(char c)
{
  if (is_alpha)
  {
    return c + 32;
  }
  else
  {
    return '\0';
  }
}

short is_common_ab(char c)
{
  if (c == ',' || c == ':' || c == '(' || c == ')' || c == '.' || c == '-' || c == '\'' || c == ' ' || c == '\t' || c == '+')
  {
    return 1;
  }
  else
  {
    return 0;
  }
}
short char_to_num(char c)
{
  if (is_number(c))
  {
    return c - '0';
  }
  else
  {
    return -1;
  }
}
short is_valid_char(char c)
{
  char temp = c;
  return is_number(temp) || is_alpha(temp) || is_common_ab(temp);
}