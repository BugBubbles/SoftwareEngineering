#include "common.h"
#include "gui.h"
//compiled under MSVC, plain char[char] is unsigned.
int main(){
    gui_circle(30, 40, 5, 1);
    gui_circle(40, 40, 5, 1);
    gui_circle(64, 32, 16, 1);
    gui_rect(1, 10, 3, 25, 1);
    gui_fillrect(65, 10, 75, 20, 1);
    gui_export_ram_source("cbj0.c");
    return 0;
}