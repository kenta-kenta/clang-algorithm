#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// 完成
void mergeSort(int arr[], int left, int right)
{
    int i, j, k, mid, tmp[100000];

    if (left < right)
    {
        mid = (left + right) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        for (i = left; i <= mid; i++)
        {
            tmp[i] = arr[i];
        }

        for (j = mid + 1; j <= right; j++)
        {
            tmp[right - (j - mid - 1)] = arr[j];
        }

        i = left;
        j = right;

        for (k = left; k <= right; k++)
        {
            if (tmp[i] < tmp[j])
            {
                arr[k] = tmp[i];
                i++;
            }
            else
            {
                arr[k] = tmp[j];
                j--;
            }
        }
    }
}

// 完成
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

void quickSort(int arr[], int start, int end)
{
    if (start < end)
    {
        int q = partision(arr, start, end);
        quickSort(arr, start, q - 1);
        quickSort(arr, q + 1, end);
    }
}

// 完成
int RandomPartision(int arr[], int start, int end)
{
    int i = rand() % (end - start + 1) + start;
    int keep = arr[i];
    arr[i] = arr[end];
    arr[end] = keep;
    return partision(arr, start, end);
}

void RandomQuickSort(int arr[], int start, int end)
{
    if (start < end)
    {
        int q = RandomPartision(arr, start, end);
        RandomQuickSort(arr, start, q - 1);
        RandomQuickSort(arr, q + 1, end);
    }
}

// 完成
void RadixSort(int arr[], int n)
{
    int i, j, k, m, p = 1, index;
    int tmp[10000][10000];
    for (i = 0; i < 10; i++)
    {
        for (j = 0; j < n; j++)
        {
            for (k = 0; k < 10000; k++)
            {
                tmp[i][k] = -1;
            }
        }
    }
    while (p <= 10000)
    {
        for (i = 0; i < n; i++)
        {
            index = (arr[i] / p) % 10;
            for (j = 0; j < 10000; j++)
            {
                if (tmp[index][j] == -1)
                {
                    tmp[index][j] = arr[i];
                    break;
                }
            }
        }
        m = 0;
        for (i = 0; i < 10; i++)
        {
            for (j = 0; j < 10000; j++)
            {
                if (tmp[i][j] != -1)
                {
                    arr[m] = tmp[i][j];
                    m++;
                }
            }
        }
        p = p * 10;
    }
}

void insert(int arr[], int n)
{
    int i, j, k, tmp;
    for (i = 1; i < n; i++)
    {
        for (j = 0; j < i; j++)
        {
            if (arr[i] < arr[j])
            {
                tmp = arr[i];
                for (k = i; k > j; k--)
                {
                    arr[k] = arr[k - 1];
                }
                arr[j] = tmp;
            }
        }
    }
}

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

void main()
{
    int n = 100000;
    int *arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL)
    {
        printf("メモリの割り当てに失敗しました\n");
        return;
    }

    srand(time(NULL));
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % 1000000; // 0から9999までのランダムな値で初期化
    }
    clock_t start, end;
    double cpu_time_used;

    start = clock();
    HeapSort(arr, n);
    end = clock();

    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("Sorted array:\n");
    // for (int i = 0; i < n; i++)
    // {
    //     printf("%d\n", arr[i]);
    // }

    printf("Time taken: %f seconds\n", cpu_time_used);
}