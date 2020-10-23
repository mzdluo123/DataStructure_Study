#include <stdio.h>
#include <stdlib.h>

int find(int *list, int length, int target)
{
    if (length == 0 || list == NULL)
    {
        return -1;
    }

    int i = 0, j = length - 1;

    while (i <= j)
    {
        int middle = middle = (j - i) / 2 + i;
        ;
        if (target > list[middle])
        {
            i = middle + 1;
        }
        if (target < list[middle])
        {
            j = middle - 1;
        }
        if (target == list[middle])
        {
            return middle;
        }
    }
    return -1;
}

int findB(int *list, int target, int end, int start) // j: 结束 i: 开始
{

    int middle = (end - start) / 2 + start;

    if (target == list[middle])
    {
        return middle;
    }

    if (start >= end+1)
    {
        return -1;
    }
    if (target < list[middle])
    {
        
        return findB(list, target,  middle - 1, start);
    }
    if (target > list[middle])

    {
        
        return findB(list, target, end, middle + 1);
    }

    return -1;
}

int main(int argc, char const *argv[])
{
    int data[] = {1, 5, 7, 9, 12, 24, 35, 43, 53, 69};
    printf("%d \n", find(&data, 10, 5));
    printf("%d \n", find(&data, 10, 53));
    printf("%d \n", find(&data, 10, 1));
    printf("%d \n", find(&data, 10, 25));

    printf("%d \n", findB(&data, 5, 9, 0));
    printf("%d \n", findB(&data, 53, 9, 0));
    printf("%d \n", findB(&data, 1, 9, 0));
    printf("%d \n", findB(&data, 25, 9, 0));
    return 0;
}
