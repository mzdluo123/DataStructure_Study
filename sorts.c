#include <stdio.h>
#include <stdlib.h>

void printlist(int *list, int length)
{

    for (int i = 0; i < length; i++)
    {
        printf("%d ", list[i]);
    }
    printf("\n");
}

void SelectionSort(int *data, int length)
{
    if (data == NULL || length == 0)
    {
        return;
    }

    int i = 0;
    int max = 0;
    for (; i < length; i++)
    {
        for (int j = i; j < length; j++)
        {
            if (data[j] > data[max])
            {
                max = j;
            }
        }
        int maxValue = data[max];
        for (int k = length - 1; k > i; k--)
        {
            data[k] = data[k - 1];
        }
        data[i] = maxValue;
    }
}

void InsertSort(int *data, int length)
{
    if (data == NULL || length == 0)
    {
        return;
    }

    int i = 0;
    int max = 0;
    for (; i < length; i++)
    {
        for (int j = i; j < length; j++)
        {
            if (data[j] > data[max])
            {
                max = j;
            }
        }
        int maxValue = data[max];
        int insert = 0;
        for (int j = 0; j <= i; j++)
        {
            if (data[j] > maxValue)
            {
                insert = j;
                break;
            }
        }

        for (int k = max; k > insert; k--)
        {
            data[k] = data[k - 1];
        }
        data[insert] = maxValue;

    }
}
void swap(int *x, int *y)
{
    int t = *x;
    *x = *y;
    *y = t;
}

void QuickSortRecursive(int data[], int start, int end)
{
    if (start >= end)
        return;
    int middle = data[end];
    int left = start, right = end - 1;
    while (left < right)
    {
        while (data[left] < middle && left < right)
        {
            left++;
        }

        while (data[right] >= middle && left < right)
        {
            right--;
        }

        swap(&data[left], &data[right]);
    }
   
    if (data[left] >= data[end])
    {
        swap(&data[left], &data[end]);
    }
    else
    {
        left++;
    }
    if (left)
    {
        QuickSortRecursive(data, start, left - 1);
    }
    QuickSortRecursive(data, left + 1, end);
}

void QuickSort(int arr[], int len)
{
    QuickSortRecursive(arr, 0, len - 1);
}

int main(int argc, char const *argv[])
{
    int data[] = {14, 5, 2, 9, 12, 24, 4, 43, 71, 53, 69};
    printlist(&data, 11);
    QuickSort(&data, 11);
    printlist(&data, 11);

    SelectionSort(&data, 11);
    printlist(&data, 11);

    InsertSort(&data, 11);
    printlist(&data, 11);
    return 0;
}
