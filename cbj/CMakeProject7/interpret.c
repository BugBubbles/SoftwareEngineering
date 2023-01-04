#include "interpret.h"
#include "gui.h"
#include <assert.h>
#pragma warning(disable:4996)
static shape shape_array[MAX_SHAPE_COUNT] = { 0 };
//supported commands
static const char *cmdstr_havearg[12] = { "disable","enabledraw","point","line","linevl","linev","rect","rectc","square","circ","circd","triangle" };
static const char *cmdstr_noarg[4] = { "draw","redraw","colorrev","export" };
static void cli_draw();
static cli_result cli_getparam(const char *source, command cmdtype);
char matchcmd(char *input, char havearg){
    char i;
    if(havearg){
        for(i = 0; i < 12; i++){
            if(!strcmp(cmdstr_havearg[i], input)){
                return i;
            }
        }
    }
    else{
        for(i = 0; i < 4; i++){
            if(!strcmp(cmdstr_noarg[i], input)){
                return i;
            }
        }
    }
    return 0xff;
}
cli_result cli_handler(const char *source){
    int k, cmdindex, index = 0xff;
    char cmdname[32] = { 0 };
    char buffer[32] = { 0 };
    char args[16] = { 0 };
    cli_result result = 0;
    k = sscanf(source, "%s", cmdname);
    cmdindex = matchcmd(cmdname, 0);//match commands without params first
    if(cmdindex != 0xff){
        switch(cmdindex){
            case 0://draw
                cli_draw();
                break;
            case 1://redraw
                gui_clear(0);
                cli_draw();
                break;
            case 2://colorrev
                gui_reverse_color();
                break;
            case 3://export
                break;
            default:
                break;
        }
        return result;
    }
    cmdindex = matchcmd(cmdname, 1);
    if(cmdindex == 0xff){//still cannot find command
        return CMD_INVALID_COMMAND;
    }
    result = cli_getparam(source + strlen(cmdstr_havearg[cmdindex]), cmdindex);
    return result;

}
static cli_result cli_getparam(const char *source, command cmdtype){
    int k, index, args[7] = { 0 };
    cli_result res = 0;
    switch(cmdtype){
        case CMD_DISABLE_SHAPE:
            k = sscanf(source, "%d", &index);
            if(k != 1){
                return CMD_INVALID_PARAM;
            }
            else{
                shape_array[index].type = 0;
                return CMD_EXEC_SUCCESS;
            }
            break;
        case CMD_ENABLE_DRAW:
            k = sscanf(source, "%d%d", &index, args);
            if(k != 2){
                return CMD_INVALID_PARAM;
            }
            else{
                shape_array[index].isshow = args[0];
                return CMD_EXEC_SUCCESS;
            }
            break;

        case CMD_POINT:
            k = sscanf(source, "%d%d%d", &index, args, args + 1);
            if(k != 3){
                return CMD_INVALID_PARAM;
            }
            else{
                shape_array[index].type = POINT;
                shape_array[index].isshow = 1;
                shape_array[index].data.pt.x = args[0];
                shape_array[index].data.pt.x = args[1];
                return CMD_EXEC_SUCCESS;
            }
            break;

        case CMD_LINE_START_END:
            k = sscanf(source, "%d%d%d%d%d", &index, args, args + 1, args + 2, args + 3);
            if(k != 5){
                return CMD_INVALID_PARAM;
            }
            else{
                shape_array[index].type = LINE;
                shape_array[index].isshow = 1;
                shape_array[index].data.lin.x1 = args[0];
                shape_array[index].data.lin.y1 = args[1];
                shape_array[index].data.lin.x2 = args[2];
                shape_array[index].data.lin.y2 = args[3];
                return CMD_EXEC_SUCCESS;
            }
            break;

        case CMD_LINE_START_DIR_LEN:
            k = sscanf(source, "%d%d%d%d%d%d", &index, args, args + 1, args + 2, args + 3, args + 4);
            if(k != 6){
                return CMD_INVALID_PARAM;
            }
            else{
                float veclen = sqrtf(args[2] * args[2] + args[3] * args[3]);
                int dx = (int)roundf(args[2] / veclen) * args[4], dy = (int)roundf(args[3] / veclen) * args[4];
                shape_array[index].type = LINE;
                shape_array[index].isshow = 1;
                shape_array[index].data.lin.x1 = args[0];
                shape_array[index].data.lin.y1 = args[1];
                shape_array[index].data.lin.x2 = args[0] + dx;
                shape_array[index].data.lin.y2 = args[1] + dy;
                return CMD_EXEC_SUCCESS;
            }
            break;

        case CMD_LINE_START_VECTOR:
            k = sscanf(source, "%d%d%d%d%d", &index, args, args + 1, args + 2, args + 3);
            if(k != 5){
                return CMD_INVALID_PARAM;
            }
            else{
                shape_array[index].type = LINE;
                shape_array[index].isshow = 1;
                shape_array[index].data.lin.x1 = args[0];
                shape_array[index].data.lin.y1 = args[1];
                shape_array[index].data.lin.x2 = args[0] + args[2];
                shape_array[index].data.lin.y2 = args[1] + args[3];
                return CMD_EXEC_SUCCESS;
            }
            break;
            //rect
        case CMD_RECT_LEFTTOP_RIGHTBOTTOM:
            k = sscanf(source, "%d%d%d%d%d%d", &index, args, args + 1, args + 2, args + 3, args + 4);
            if(k != 6){
                return CMD_INVALID_PARAM;
            }
            else{
                shape_array[index].type = args[4] ? FILLEDRECT : RECT;
                shape_array[index].isshow = 1;
                shape_array[index].data.lin.x1 = args[0];
                shape_array[index].data.lin.y1 = args[1];
                shape_array[index].data.lin.x2 = args[0] + args[2];
                shape_array[index].data.lin.y2 = args[1] + args[3];
                return CMD_EXEC_SUCCESS;
            }
        case CMD_RECT_CENTER_WIDTH_HEIGHT:
            k = sscanf(source, "%d%d%d%d%d%d", &index, args, args + 1, args + 2, args + 3, args + 4);
            if(k != 6){
                return CMD_INVALID_PARAM;
            }
            else{
                shape_array[index].type = args[4] ? FILLEDRECT : RECT;
                shape_array[index].isshow = 1;
                shape_array[index].data.lin.x1 = args[0] - args[2] / 2;
                shape_array[index].data.lin.y1 = args[1] - args[3] / 2;
                shape_array[index].data.lin.x2 = args[0] + args[2] / 2;
                shape_array[index].data.lin.y2 = args[1] + args[3] / 2;
                return CMD_EXEC_SUCCESS;
            }
            break;
        case CMD_RECT_SQUARE:
            k = sscanf(source, "%d%d%d%d%d", &index, args, args + 1, args + 2, args + 3);
            if(k != 5){
                return CMD_INVALID_PARAM;
            }
            else{
                shape_array[index].type = args[3] ? FILLEDRECT : RECT;
                shape_array[index].isshow = 1;
                shape_array[index].data.lin.x1 = args[0] - args[2] / 2;
                shape_array[index].data.lin.y1 = args[1] - args[2] / 2;
                shape_array[index].data.lin.x2 = args[0] + args[2] / 2;
                shape_array[index].data.lin.y2 = args[1] + args[2] / 2;
                return CMD_EXEC_SUCCESS;
            }
            break;
            //circle
        case CMD_CIRCLE_CENTER_RADIUS:
            k = sscanf(source, "%d%d%d%d", &index, args, args + 1, args + 2);
            if(k != 4){
                return CMD_INVALID_PARAM;
            }
            else{
                shape_array[index].type = CIRCLE;
                shape_array[index].isshow = 1;
                shape_array[index].data.circ.x = args[0];
                shape_array[index].data.circ.y = args[1];
                shape_array[index].data.circ.r = args[2];
                return CMD_EXEC_SUCCESS;
            }
            break;
        case CMD_CIRCLE_CENTER_DIAM:
            k = sscanf(source, "%d%d%d%d", &index, args, args + 1, args + 2);
            if(k != 4){
                return CMD_INVALID_PARAM;
            }
            else{
                shape_array[index].type = CIRCLE;
                shape_array[index].isshow = 1;
                shape_array[index].data.circ.x = args[0];
                shape_array[index].data.circ.y = args[1];
                shape_array[index].data.circ.r = args[2] / 2;
                return CMD_EXEC_SUCCESS;
            }
            break;
        case CMD_TRIANGLE:
            k = sscanf(source, "%d%d%d%d%d%d%d", &index, args, args + 1, args + 2, args + 3, args + 4, args + 5);
            if(k != 7){
                return CMD_INVALID_PARAM;
            }
            else{
                shape_array[index].type = TRIANGLE;
                shape_array[index].isshow = 1;
                shape_array[index].data.tri.x1 = args[0];
                shape_array[index].data.tri.y1 = args[1];
                shape_array[index].data.tri.x2 = args[2];
                shape_array[index].data.tri.y2 = args[3];
                shape_array[index].data.tri.x3 = args[4];
                shape_array[index].data.tri.y3 = args[5];
                return CMD_EXEC_SUCCESS;
            }
            break;
        default:
            return CMD_INVALID_PARAM;
    }
}
static void cli_draw(){
    int i;
    for(i = 0; i < MAX_SHAPE_COUNT; i++){
        switch(shape_array[i].type){//enabled
            case POINT:
                gui_setpixel(shape_array[i].data.pt.x, shape_array[i].data.pt.y, shape_array[i].isshow);
                break;
            case LINE:
                gui_line(shape_array[i].data.lin.x1, shape_array[i].data.lin.y1, shape_array[i].data.lin.x2, shape_array[i].data.lin.y2, shape_array[i].isshow);
                break;
            case RECT:
                gui_rect(shape_array[i].data.lin.x1, shape_array[i].data.lin.y1, shape_array[i].data.lin.x2, shape_array[i].data.lin.y2, shape_array[i].isshow);
                break;
            case FILLEDRECT:
                gui_fillrect(shape_array[i].data.lin.x1, shape_array[i].data.lin.y1, shape_array[i].data.lin.x2, shape_array[i].data.lin.y2, shape_array[i].isshow);
                break;
            case CIRCLE:
                gui_circle(shape_array[i].data.circ.x, shape_array[i].data.circ.y, shape_array[i].data.circ.r, shape_array[i].isshow);
                break;
            case TRIANGLE:
                gui_triangle(shape_array[i].data.tri.x1, shape_array[i].data.tri.y1, shape_array[i].data.tri.x2, shape_array[i].data.tri.y2, shape_array[i].data.tri.x3, shape_array[i].data.tri.y3, shape_array[i].isshow);
                break;
            default:
                break;
        }
    }
}