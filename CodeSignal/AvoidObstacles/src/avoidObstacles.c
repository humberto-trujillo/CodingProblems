
/*
You are given an array of integers representing coordinates of obstacles situated on a straight line.

Assume that you are jumping from the point with coordinate 0 to the right. You are allowed only to make jumps of the same length represented by some integer.

Find the minimal length of the jump enough to avoid all the obstacles.

Example

For inputArray = [5, 3, 6, 7, 9], the output should be
avoidObstacles(inputArray) = 4.

Input/Output

[execution time limit] 0.5 seconds (c)

[input] array.integer inputArray

Non-empty array of positive integers.

Guaranteed constraints:
2 ≤ inputArray.length ≤ 1000,
1 ≤ inputArray[i] ≤ 1000.

[output] integer

The desired length.
*/

#include "avoidObstacles.h"

bool isInList(arr_integer array, int value)
{
    int i=0;
    for(i=0;i<array.size;i++)
    {
        if(array.arr[i] == value)
        {
            return true;
        }
    }
    return false;
}
int avoidObstacles(arr_integer inputArray)
{
    int max = 0;
    int min = 2;
    int i=0;
    for(i=0;i<inputArray.size;i++)
    {
        if(inputArray.arr[i]>max)
        {
            max = inputArray.arr[i];
        }
    }
    for(i=0;i<max+min;i+=min)
    {
        if(isInList(inputArray,i))
        {
            min++;
            i=0;
        }
    }
    return min;
}
