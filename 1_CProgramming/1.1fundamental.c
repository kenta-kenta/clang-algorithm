#include <stdio.h>

void main()
{
    // 挿入ソート
    int arr[] = {1, 5, 3, 6, 2, 34, 15109};
    insert(arr, 7);
    for (int i = 0; i < 7; i++)
    {
        printf("%d\n", arr[i]);
    }

    // 素数判定
    isPrime(14);

    // 最大公約数を求める
    maxDiv(99, 22);
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

void isPrime(int n)
{
    if (n < 2)
    {
        return;
    }
    int i;
    for (i = 2; i < n; i++)
    {
        if (n % i == 0)
        {
            printf("%d: 素数ではない\n", n);
            return;
        }
    }
    printf("%d: 素数である\n", n);
}

void maxDiv(int m, int n)
{
    if (m < n || m < 0)
    {
        return;
    }
    if (n == 0)
    {
        printf("最大公約数：%d\n", m);
    }
    else
    {
        maxDiv(n, m % n);
    }
}