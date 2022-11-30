// CTestLib.cpp : Defines the entry point for the application.
//
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <windows.h>
#include "cJSON.h"
__declspec(dllexport) int __cdecl test(){
    cJSON *p = cJSON_Parse("{\"test\":\"cbjo\"}");
    char *x = cJSON_GetStringValue(p->child);
    int res = MessageBoxA(0, x, "test", 0);
    cJSON_Delete(p);
    p = 0;
    return res;
}