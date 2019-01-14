#ifndef AVOIDOBSTACLES_H_   /* Include guard */
#define AVOIDOBSTACLES_H_

#define bool int
#define true 1
#define false 0

typedef struct arr_integer
{
   int size;
   int *arr;
} arr_integer;

bool isInList(arr_integer array, int value);
int avoidObstacles(arr_integer inputArray);

#endif // AVOIDOBSTACLES_H_