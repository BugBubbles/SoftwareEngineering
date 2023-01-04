#ifndef COMMON_H
#define COMMON_H
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>

#ifndef MAX_SHAPE_COUNT
#define MAX_SHAPE_COUNT 32
#endif // !MAX_SHAPE_COUNT
#ifndef MAX
#define MAX(a,b) (((a)>(b))?(a):(b))
#endif // !MAX
#ifndef MIN
#define MIN(a,b) (((a)<(b))?(a):(b))
#endif // !MIN
#ifndef CROL
#define CROL(X,i,n) ((((X)<<(i))|((X)>>((n)-(i))))&((1<<(n))-1))
#endif // !CROL
#ifndef CROR
#define CROR(X,i,n) ((((X)>>(i))|((X)<<((n)-(i))))&((1<<(n))-1))
#endif // !CROR

#endif // !COMMON_H
