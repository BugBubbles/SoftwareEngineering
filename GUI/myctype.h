#ifndef CBJ_CTYPE_WORK
#define CBJ_CTYPE_WORK
//reference:https://en.cppreference.com/w/c/string/byte
#define USEFUNC 1
#if(USEFUNC)
#undef cbj_iscntrl
#undef cbj_isprint
#undef cbj_isspace
#undef cbj_isblank
#undef cbj_isgraph
#undef cbj_isupper
#undef cbj_islower
#undef cbj_isalpha
#undef cbj_isdigit
#undef cbj_isxdigit
#undef cbj_isalnum
#undef cbj_ispunct
#undef cbj_tolower
#undef cbj_toupper
#ifdef __cplusplus
extern "C"{
#endif // __cplusplus
    int cbj_iscntrl(int c);
    int cbj_isprint(int c);
    int cbj_isspace(int c);
    int cbj_isblank(int c);
    int cbj_isgraph(int c);
    int cbj_isupper(int c);
    int cbj_islower(int c);
    int cbj_isalpha(int c);
    int cbj_isdigit(int c);
    int cbj_isxdigit(int c);
    int cbj_isalnum(int c);
    int cbj_ispunct(int c);
    int cbj_tolower(int c);
    int cbj_toupper(int c);
#ifdef __cplusplus
}
#endif // __cplusplus

#else
#define cbj_iscntrl(c) (((c)<' ')||((c)==0x7f))
#define cbj_isprint(c) (((c)>=' ')&&((c)<0x7f))
#define cbj_isspace(c) (((c)==' ')||((c)>='\t')&&((c)<='\r'))
#define cbj_isblank(c) (((c)==' ')||((c)=='\t'))
#define cbj_isgraph(c) (((c)>' ')&&((c)<='~'))
//#define cbj_ispunct(c) ((((c)>='!')&&((c)<='//'))||((c>=':')&&(c<='@'))||(((c)>='[')&&((c)<='`'))||(((c)>='{')&&((c)<='~')))

#define cbj_isupper(c) (((c)>='A')&&((c)<='Z'))
#define cbj_islower(c) (((c)>='a')&&((c)<='z'))
#define cbj_isalpha(c) (cbj_isupper(c)||cbj_islower(c))
#define cbj_isdigit(c) (((c)>='0')&&((c)<='9'))
#define cbj_isxdigit(c) (cbj_isdigit(c)||(((c)>='a')&&((c)<='f'))||(((c)>='A')&&((c)<='F')))
#define cbj_isalnum(c) (cbj_isdigit(c)||cbj_isalpha(c))
#define cbj_ispunct(c) (cbj_isgraph(c)&&(!cbj_isalnum(c)))

#define cbj_tolower(c) ((cbj_isupper(c))?((c)+32):(c))
//'a'[97]-'A'[65]=32
#define cbj_toupper(c) ((cbj_islower(c))?((c)-32):(c))

#endif // USEFUNC



#endif // !CBJ_CTYPE_WORK
