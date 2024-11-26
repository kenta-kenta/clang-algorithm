#include <stdio.h>

// 完成
int Max(int arr[], int n)
{
    int i, max = arr[0];
    for (i = 1; i < n; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    return max;
}

int Min(int arr[], int n)
{
    int i, min = arr[0];
    for (i = 1; i < n; i++)
    {
        if (arr[i] < min)
        {
            min = arr[i];
        }
    }
    return min;
}

int partision(int arr[], int start, int end)
{
    int pivot = arr[end];
    int i = start - 1;
    int keep, j;
    for (j = start; j < end; j++)
    {
        if (arr[j] <= pivot)
        {
            i = i + 1;
            keep = arr[i];
            arr[i] = arr[j];
            arr[j] = keep;
        }
    }
    keep = arr[i + 1];
    arr[i + 1] = arr[j];
    arr[j] = keep;
    return i + 1;
}

int RandomPartision(int arr[], int start, int end)
{
    int i = rand() % (end - start) + start;
    int keep = arr[i];
    arr[i] = arr[end];
    arr[end] = keep;
    return partision(arr, start, end);
}

int RandomizedSelect(int arr[], int pivot, int end, int select)
{
    if (pivot == end)
    {
        return arr[pivot];
    }
    int q = RandomPartision(arr, pivot, end);
    int k = q - pivot + 1;
    if (select == k)
    {
        return arr[q];
    }
    else if (select < k)
    {
        return RandomizedSelect(arr, pivot, q - 1, select);
    }
    else
    {
        return RandomizedSelect(arr, q + 1, end, select - k);
    }
}

int Selection(int arr[], int n, int select)
{
    return RandomizedSelect(arr, 0, n - 1, n - select + 1);
}

void main()
{
    int arr[10] = {1, 3, 5, 7, 9, 2, 4, 6, 8, 10};
    printf("%d\n", Selection(arr, 10, 3));
}