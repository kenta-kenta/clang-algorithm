#include <stdio.h>

double fibonachRec(int n)
{
    double sum = 0;
    if (n == 1 || n == 2)
    {
        return 1;
    }
    sum = fibonachRec(n - 1) + fibonachRec(n - 2);
    return sum;
}

double fibonachIte(int n)
{
    double num1 = 0;
    double num2 = 1;
    double tmp;
    for (int i = 2; i <= n; i++)
    {
        tmp = num2;
        num2 = num1 + num2;
        num1 = tmp;
    }
    return num2;
}

double fibonachTrec(int n, double a, double b)
{
    if (n == 0)
    {
        return a;
    }
    return fibonachTrec(n - 1, b, a + b);
}

int Hanoi(int n)
{
    if (n == 1)
    {
        return 1;
    }
    return 2 * Hanoi(n - 1) + 1;
}

void mergeSort(int arr[], int left, int right)
{
    int i, j, k, mid, tmp[10000];

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

int main()
{
    // フィボナッチ数(再帰)
    // printf("%e\n", fibonachRec(10));
    // printf("%e\n", fibonachRec(40));
    // printf("%e\n", fibonachRec(1000));

    // // フィボナッチ数(反復法)
    // printf("%e\n", fibonachIte(10));
    // printf("%e\n", fibonachRec(40));
    // printf("%e\n", fibonachRec(100));

    // // フィボナッチ数(末尾再帰)
    // printf("%e\n", fibonachTrec(10, 0.0, 1.0));
    // printf("%e\n", fibonachTrec(40, 0.0, 1.0));
    // printf("%e\n", fibonachTrec(1000, 0.0, 1.0));

    // // ハノイの塔の手順数
    // printf("%d\n", Hanoi(3));

    // // マージソート
    int arr[] = {1, 8, 4, 2, 4, 90, 53, 7, 9};
    mergeSort(arr, 0, 8);
    for (int i = 0; i <= 8; i++)
    {
        printf("%d\n", arr[i]);
    }

    return 0;
}
