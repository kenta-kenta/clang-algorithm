#include <stdio.h>

void main()
{
    int arr[] = {2, 3, 4, 1, 2, 9};
    MaxHeapify(arr, 1);
}

void MaxHeapify(int arr[], int i)
{
    int left, right, largest, keep;
    left = 2 * i;
    right = 2 * i + 1;

    if (sizeof(arr) >= left && arr[left] > arr[right])
    {
        largest = left;
    }
    else
    {
        largest = right;
    }

    if (sizeof(arr) >= right && arr[right] > arr[largest])
    {
        largest = right;
    }

    if (largest != i)
    {
        keep = arr[i];
        arr[i] = arr[largest];
        arr[largest] = keep;
        MaxHeapify(arr, largest);
    }
}