#include <stdio.h>

// キューの実装
// キューに要素を追加
void enqueue(int arr[], int x, int *tail)
{
    if (*tail == 10)
    {
        printf("error: stack overflow\n");
    }
    else
    {
        arr[*tail] = x;
        *tail = *tail + 1;
    }
}

// キューから要素を取り出す
int dequeue(int arr[], int *head)
{
    int x = arr[*head];
    if (*head == 10)
    {
        printf("error: stack underflow\n");
        return -1;
    }
    else
    {
        *head = *head + 1;
    }
    return x;
}

void main()
{
    int arr[10];
    int tail = 0;
    int head = 0;
    for (int i = 1; i < 12; i++)
    {
        enqueue(arr, i, &tail);
    }
    for (int i = 1; i < 12; i++)
    {
        printf("%d\n", dequeue(arr, &head));
    }
}
