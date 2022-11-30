#include "myctype.h"
#if(USEFUNC)
int cbj_iscntrl(int c){
    return ((c < ' ') || (c == 0x7f));
}
int cbj_isprint(int c){
    return ((c >= ' ') && (c < 0x7f));
}
int cbj_isspace(int c){
    return ((c == ' ') || (c >= '\t') && (c <= '\r'));
}
int cbj_isblank(int c){
    return ((c == ' ') || (c == '\t'));
}
int cbj_isgraph(int c){
    return ((c > ' ') && (c <= '~'));
}
int cbj_isupper(int c){
    return ((c >= 'A') && (c <= 'Z'));
}
int cbj_islower(int c){
    return ((c >= 'a') && (c <= 'z'));
}
int cbj_isalpha(int c){
    return (cbj_isupper(c) || cbj_islower(c));
}
int cbj_isdigit(int c){
    return ((c >= '0') && (c <= '9'));
}
int cbj_isxdigit(int c){
    return (cbj_isdigit(c) || ((c >= 'a') && (c <= 'f')) || ((c >= 'A') && (c <= 'F')));
}
int cbj_isalnum(int c){
    return (cbj_isdigit(c) || cbj_isalpha(c));
}
int cbj_ispunct(int c){
    return (cbj_isgraph(c) && (!cbj_isalnum(c)));
}
int cbj_tolower(int c){
    return ((cbj_isupper(c)) ? (c+32) : c);
}
int cbj_toupper(int c){
    return ((cbj_islower(c)) ? (c-32) : c);
}
#endif // USEFUNC