#include <stdio.h>
#include "avoidObstacles.h"


int main(int argc, char const *argv[])
{
    int l1[5] = {5, 3, 6, 7, 9};
    int l2[2] = {2, 3};
    int l3[5] = {1, 4, 10, 6, 2};

    arr_integer arr[3];
    arr[0].arr = l1;
    arr[0].size = 5;

    arr[1].arr = l2;
    arr[1].size = 2;

    arr[2].arr = l3;
    arr[2].size = 5;


    for(int i = 0; i < 3; i++)
    {
        printf("Jumps = %d\n", avoidObstacles(arr[i]));
    }
    return 0;
}
