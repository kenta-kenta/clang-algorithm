#include <stdio.h>

void MaxHeapify(int arr[], int len, int parent)
{
    int left, right, largest, keep;
    left = 2 * parent;
    right = 2 * parent + 1;

    if (len > left && arr[left] > arr[parent])
    {
        largest = left;
    }
    else
    {
        largest = parent;
    }

    if (len > right && arr[right] > arr[largest])
    {
        largest = right;
    }

    if (largest != parent)
    {
        keep = arr[parent];
        arr[parent] = arr[largest];
        arr[largest] = keep;
        MaxHeapify(arr, len, largest);
    }
}

void BuildMaxHeap(int arr[], int len)
{
    int maxheap = floor(len / 2) - 1;
    for (int i = maxheap; i >= 0; i--)
    {
        MaxHeapify(arr, len, i);
    }
}

int HeapExtractMax(int arr[], int len)
{
    int max = arr[0];
    arr[0] = arr[len - 1];
    len = len - 1;
    MaxHeapify(arr, len, 1);
    return max;
}

void MaxInsertHeap(int arr[], int len, int insert)
{
    arr[len] = insert;
    int i = len;
    while (i > 0 && arr[(i - 1) / 2] < arr[i])
    {
        int temp = arr[i];
        arr[i] = arr[(i - 1) / 2];
        arr[(i - 1) / 2] = temp;
        i = (i - 1) / 2;
    }
}

void HeapSort(int arr[], int len)
{
    for (int i = 0; i < len; i++)
    {
        BuildMaxHeap(arr, len - i);
        int keep = arr[0];
        for (int j = 0; j < len - 1; j++)
        {
            arr[j] = arr[j + 1];
        }
        arr[len - 1] = keep;
    }
}

// Priority queue ----------------------------------------------------------------------
typedef struct
{
    float priority;
    int key;
} Element;

void PriorityMaxHeapify(Element heap[], int size, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < size && heap[left].priority > heap[largest].priority)
    {
        largest = left;
    }

    if (right < size && heap[right].priority > heap[largest].priority)
    {
        largest = right;
    }

    if (largest != i)
    {
        Element temp = heap[i];
        heap[i] = heap[largest];
        heap[largest] = temp;
        PriorityMaxHeapify(heap, size, largest);
    }
}

void BuildPriorityMaxHeap(Element heap[], int size)
{
    int maxheap = floor(size / 2) - 1;
    for (int i = maxheap; i >= 0; i--)
    {
        PriorityMaxHeapify(heap, size, i);
    }
}

void Insert(Element heap[], int *size, Element element)
{
    *size = *size + 1;
    heap[*size] = element;
    int i = *size;
    while (i > 0 && heap[(i - 1) / 2].priority < heap[i].priority)
    {
        Element temp = heap[i];
        heap[i] = heap[(i - 1) / 2];
        heap[(i - 1) / 2] = temp;
        i = (i - 1) / 2;
    }
}

Element Maximum(Element heap[])
{
    return heap[0];
}

Element ExtractMax(Element heap[], int *size)
{
    *size = *size - 1;
    Element max;
    max.priority = heap[0].priority;
    max.key = heap[0].key;
    heap[0].priority = heap[*size].priority;
    heap[0].key = heap[*size].key;
    // PriorityMaxHeapify(heap, *size, 0);
    return heap[0];
}

void IncreaseKey(Element heap[], int i, int key)
{
    heap[i].key = key;
    while (i > 0 && heap[(i - 1) / 2].priority < heap[i].priority)
    {
        Element temp = heap[i];
        heap[i] = heap[(i - 1) / 2];
        heap[(i - 1) / 2] = temp;
        i = (i - 1) / 2;
    }
}

void main()
{
    // int arr[] = {2, 3, 4, 1, 2, 9};
    // MaxHeapify(arr, 6, 0);
    // BuildMaxHeap(arr, 6);
    // printf("%d\n", HeapExtractMax(arr, 6));
    // MaxInsertHeap(arr, 6, 5);
    // HeapSort(arr, 6);
    // for (int i = 0; i < 6; i++)
    // {
    //     printf("%d\n", arr[i]);
    // }

    Element heap[6] = {{3, 1}, {2, 2}, {4, 3}, {1, 4}, {2, 5}, {9, 6}};
    int size = 6;
    // PriorityMaxHeapify(heap, size, 0);
    BuildPriorityMaxHeap(heap, size);
    // printf("%f, %d\n", Maximum(heap).priority, Maximum(heap).key);
    printf("%f, %d\n", ExtractMax(heap, &size).priority, ExtractMax(heap, &size).key);
    // IncreaseKey(heap, 2, 10);
    for (int i = 0; i < 6; i++)
    {
        printf("%f, %d\n", heap[i].priority, heap[i].key);
    }
}