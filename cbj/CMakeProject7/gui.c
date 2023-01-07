#include "gui.h"
#include "common.h"

static char oledram[1024] = {0};
// set a pixel's value(ON[1]/OFF[0]) at(x,y)  aka. draw point
#ifdef _WIN32
char gui_export_ram_source(const char *filename)
{
  FILE *fp = fopen(filename, "w");
  int i;
  if (fp)
  {
    fputs("const char oledbmp[1024]={\n", fp);
    for (i = 0; i < 1023; i++)
    {
      fprintf(fp, "0x%x,", oledram[i]);
    }
    fprintf(fp, "0x%x};\n", oledram[1023]);
    fclose(fp);
    return 0;
  }
  return 3; // invalid file operation
}
char gui_export_ram_binary(const char *filename)
{
  FILE *fp = fopen(filename, "wb");
  if (fp)
  {
    fwrite(oledram, 1, 1024, fp);
    fclose(fp);
    return 0;
  }
  return 3; // invalid file operation
}
#endif // _WIN32

// copy current OLED display RAM to specified buffer
void gui_export_ram_array(char *buffer)
{
  memcpy(buffer, oledram, 1024);
}
// set one pixel at(x,y)
// color: 0:black, nonzero(1,..):white
void gui_setpixel(char x, char y, char color)
{
  if (color)
  { // white
    // oledram[(y/8)*128+x]|=(1<<(y%8))
    oledram[((y >> 3u) << 7u) | x] |= (1 << (y & 7)) & 0xff;
  }
  else
  { // black
    oledram[((y >> 3u) << 7u) | x] &= ~((1 << (y & 7)) & 0xff);
  }
}
void gui_reverse_color()
{
  int i;
  for (i = 0; i < 1024; i++)
  {
    oledram[i] = ~oledram[i];
  }
}
// clear the entire drawing area
// color: 0:black, nonzero(1,..):white
void gui_clear(char color)
{
  if (color)
  {
    memset(oledram, 0xff, 1024);
  }
  else
  {
    memset(oledram, 0, 1024);
  }
}
// fill rectangle area
void gui_fillrect(char sx, char sy, char ex, char ey, char color)
{
  char i, j, w = ex - sx + 1, h = ey - sy + 1;
  for (i = 0; i < h; i++)
  {
    for (j = 0; j < w; j++)
    {
      gui_setpixel(sx + j, sy + i, color);
    }
  }
}
void gui_line(char x1, char y1, char x2, char y2, char color)
{
  unsigned short t;
  int xerr = 0, yerr = 0, dx, dy, dis;
  int incx, incy, urow, ucol;
  dx = x2 - x1;
  dy = y2 - y1;
  if (dx > 0)
  {
    incx = 1;
  }
  else if (dx == 0)
  { // vertical line
    incx = 0;
  }
  else
  {
    incx = -1;
    dx = -dx;
  }
  if (dy > 0)
  {
    incy = 1;
  }
  else if (dy == 0)
  { // horizontal line
    incy = 0;
  }
  else
  {
    incy = -1;
    dy = -dy;
  }
  dis = MAX(dx, dy);
  urow = x1;
  ucol = y1;
  for (t = 0; t <= dis + 1; t++)
  {
    gui_setpixel(urow, ucol, color);
    xerr += dx;
    yerr += dy;
    if (xerr > dis)
    {
      xerr -= dis;
      urow += incx;
    }
    if (yerr > dis)
    {
      yerr -= dis;
      ucol += incy;
    }
  }
}
void gui_rect(char x1, char y1, char x2, char y2, char color)
{
  gui_line(x1, y1, x2, y1, color);
  gui_line(x1, y1, x1, y2, color);
  gui_line(x1, y2, x2, y2, color);
  gui_line(x2, y1, x2, y2, color);
}
static void _gui_circle8(char xc, char yc, char x, char y, char color)
{
  gui_setpixel(xc + x, yc + y, color);
  gui_setpixel(xc - x, yc + y, color);
  gui_setpixel(xc + x, yc - y, color);
  gui_setpixel(xc - x, yc - y, color);
  gui_setpixel(xc + y, yc + x, color);
  gui_setpixel(xc - y, yc + x, color);
  gui_setpixel(xc + y, yc - x, color);
  gui_setpixel(xc - y, yc - x, color);
}
void gui_circle(char xc, char yc, char r, char color)
{
  int x = 0, y = r, d = 3 - 2 * r;
  while (x <= y)
  {
    _gui_circle8(xc, yc, x, y, color);
    if (d < 0)
    {
      d += 4 * x + 6;
    }
    else
    {
      d += (4 * (x - y) + 10);
      y--;
    }
    x++;
  }
}
void gui_triangle(char x0, char y0, char x1, char y1, char x2, char y2, char color)
{
  gui_line(x0, y0, x1, y1, color);
  gui_line(x1, y1, x2, y2, color);
  gui_line(x2, y2, x0, y0, color);
}