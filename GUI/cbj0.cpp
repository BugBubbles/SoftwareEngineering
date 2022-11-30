#include <stdio.h>
#include <ctype.h>
#include "myctype.h"
typedef struct _data{
    struct _data *pnext;
}data;
int main(){
    int i = 0, j = 0, k;
    freopen("result.txt", "w", stdout);
    for(i = 0; i < 8; i++){
        for(j = 0; j < 16; j++){
            k = j | (i << 4);
            printf("asc:%d\n", k);
            if(cbj_isprint(k)){
                printf("isprint:1 %c\n", k);
                printf("tolower:%d %c \n", cbj_tolower(k), cbj_tolower(k));
                printf("toupper:%d %c \n", cbj_toupper(k), cbj_toupper(k));
            }
            printf("iscntrl:%d %d\n", cbj_iscntrl(k), iscntrl(k));
            printf("isspace:%d %d\n", cbj_isspace(k), isspace(k));
            printf("isblank:%d %d\n", cbj_isblank(k), isblank(k));
            printf("isgraph:%d %d\n", cbj_isgraph(k), isgraph(k));
            printf("ispunct:%d %d\n", cbj_ispunct(k), ispunct(k));
            printf("isalnum:%d %d\n", cbj_isalnum(k), isalnum(k));
            printf("isalpha:%d %d\n", cbj_isalpha(k), isalpha(k));
            printf("isupper:%d %d\n", cbj_isupper(k), isupper(k));
            printf("islower:%d %d\n", cbj_islower(k), islower(k));
            printf("isdigit:%d %d\n", cbj_isdigit(k), isdigit(k));
            printf("isxdigit:%d %d\n", cbj_isxdigit(k), isxdigit(k));
        }
    }
    return 0;
}