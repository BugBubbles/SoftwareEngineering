#ifndef GUI_H
#define GUI_H
#ifdef __cplusplus
extern "C"{
#endif // __cplusplus
#define GUI_PAGECOUNT 8
#define GUI_PAGEWIDTH 128
#define GUI_COLOR_WHITE 1
#define GUI_COLOR_BLACK 0
    //export the current OLED display RAM to specific c source file
#ifdef _WIN32
    char gui_export_ram_source(const char *filename);
#endif // _WIN32

    void gui_export_ram_array(char *buffer);
    //set pixel at (x,y) 
    void gui_setpixel(char x, char y, char color);
    void gui_clear(char color);
    void gui_fillrect(char x1, char y1, char x2, char y2, char color);
    void gui_rect(char x1, char y1, char x2, char y2, char color);
    void gui_line(char x1, char y1, char x2, char y2, char color);
    void gui_circle(char xc, char yc, char r, char color);
    void gui_triangle(char x0, char y0, char x1, char y1, char x2, char y2, char color);
#ifdef __cplusplus
}
#endif // __cplusplus
#endif // !GUI_H
