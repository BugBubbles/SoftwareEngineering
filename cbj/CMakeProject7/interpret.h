#ifndef INTERPRET_H
#define INTERPRET_H
#include "common.h"
#ifdef __cplusplus
extern "C"{
#endif // __cplusplus

    //basic types for shapes to be displayed on a 128*64 OLED display
    //basic type of point(x,y)
    typedef struct _point{
        char x, y;
    }point;
    //basic type of rectangle and line
    //filled rectangle: (x1,y1) left top,(x2,y2) right bottom
    //rectangle: (x1,y1) left top,(x2,y2) right bottom
    //line: (x1,y1) start point, (x2,y2) finish point
    typedef struct _pointpair{
        char x1, y1;
        char x2, y2;
    }line, rect, filled_rect;
    //basic type of circle
    //circle's center:(x,y), radius:r
    typedef struct _circle{
        char x, y, r;
    }circle;
    typedef struct _triangle{
        char x1, y1, x2, y2, x3, y3;
    }triangle;
    typedef enum _shapetype{
        UNUSED = 0,//not used
        POINT = 1,
        LINE = 2,
        RECT = 3,
        FILLEDRECT = 4,
        CIRCLE = 5,
        TRIANGLE = 6
    }shapetype;
    typedef struct _shape{
        //if 'type' is set to 0[UNUSED], the shape is invalid, ignored.
        //else the shape of specific type[1,2,3,4,5,6] can be drawn.
        shapetype type;
        //if 'isshow' is set to 0, the shape is ignored when drawing the OLED image.
        char isshow;
        union _data{
            point pt;//point
            line lin;
            circle circ;
            triangle tri;
        }data;
          
    }shape;
    typedef enum _cmdtype{
        CMD_DISABLE_SHAPE=0,
        CMD_ENABLE_DRAW,
        CMD_POINT,
        CMD_LINE_START_END,
        CMD_LINE_START_DIR_LEN,
        CMD_LINE_START_VECTOR,
        CMD_RECT_LEFTTOP_RIGHTBOTTOM,
        CMD_RECT_CENTER_WIDTH_HEIGHT,
        CMD_RECT_SQUARE,
        CMD_CIRCLE_CENTER_RADIUS,
        CMD_CIRCLE_CENTER_DIAM,
        CMD_TRIANGLE,

    }command;
    typedef char cli_result;
#define CMD_EXEC_SUCCESS 0
#define CMD_INVALID_COMMAND 1
#define CMD_INVALID_PARAM 2
#ifdef __cplusplus
}
#endif // __cplusplus
#endif // !INTERPRET_H
