#include <stdio.h>

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

void RadixSort(int arr[], int n)
{
    int i, j, k, m, p = 1, index = 0;
    int tmp[10][10000]; // 10桁のバケット、各バケットに最大10000個の要素を格納

    // 配列の最大値を求める
    for (i = 0; i < n; i++)
    {
        if (arr[i] > index)
        {
            index = arr[i];
        }
    }

    // 最大値の桁数を求める
    int maxDigits = 0;
    while (index > 0)
    {
        maxDigits++;
        index /= 10;
    }

    // 基数ソートのメインループ
    for (int digit = 0; digit < maxDigits; digit++)
    {
        // バケットを初期化
        for (i = 0; i < 10; i++)
        {
            for (j = 0; j < 10000; j++)
            {
                tmp[i][j] = -1;
            }
        }

        // 各要素を対応するバケットに格納
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

        // バケットから元の配列に要素を戻す
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

        // 次の桁に進む
        p *= 10;
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
    left = 2 * parent + 1;
    right = 2 * parent + 2;

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
    BuildMaxHeap(arr, len);
    for (int i = len - 1; i >= 1; i--)
    {
        int keep = arr[0];
        arr[0] = arr[i];
        arr[i] = keep;
        len--;
        MaxHeapify(arr, len, 0);
    }
}

void main()
{
    int arr[] = {3, 1, 4, 9, 2, 6, 5, 7, 8, 10};
    RadixSort(arr, 10);
    for (int i = 0; i < 11; i++)
    {
        printf("%d\n", arr[i]);
    }
}