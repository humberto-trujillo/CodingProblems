#ifndef BOXBLUR_H_   /* Include guard */
#define BOXBLUR_H_

#include <stdlib.h>

#define bool int
#define true 1
#define false 0

typedef struct arr_integer
{
   int size;
   int *arr;
} arr_integer;

typedef struct arr_arr_integer
{
   int size;
   arr_integer *arr;
} arr_arr_integer;

arr_integer alloc_arr_integer(int len);
arr_arr_integer alloc_arr_arr_integer(int len);
int mean(arr_arr_integer image, int i, int j);
arr_arr_integer boxBlur(arr_arr_integer image);

#endif // BOXBLUR_H_