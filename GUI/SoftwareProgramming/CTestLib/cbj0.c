#include <stdio.h>
#include <windows.h>
#include "cJSON.h"
int main(){
    cJSON *p = cJSON_Parse("{\"test\":\"cbjo\"}");
    char *x = cJSON_GetStringValue(p->child);
    int res = MessageBoxA(0, x, "test", 0);
    cJSON_Delete(p);
    return 0;
}