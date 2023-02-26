// Find min-max values ​​in an array

#include "./libs/findMinMax.h"

// A utility function that returns index of minimum value in arr[]
int getMin(int arr[])
{   
    int minInd = 0;
    for (int i = 1; i < (int)sizeof(arr)/sizeof(int); i++)
        if (arr[i] < arr[minInd])
            minInd = i;
    return minInd;
}

// A utility function that returns index of maximum value in arr[]
int getMax(int arr[])
{
    int maxInd = 0;
    for (int i = 1; i < (int)sizeof(arr)/sizeof(int); i++)
        if (arr[i] > arr[maxInd])
            maxInd = i;
    return maxInd;
}

// A utility function to return minimum of 2 values
int minOf2(int x, int y)
{
    return (x < y) ? x : y;
}

// amount[p] indicates the net amount to be credited/debited
// to/from person 'p'
// If amount[p] is positive, then i'th person will amount[i]
// If amount[p] is negative, then i'th person will give  -amount[i]