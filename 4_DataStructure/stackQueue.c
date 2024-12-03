#include <stdio.h>

// スタックの実装
int stackEmpty(int top)
{
    if (top == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int stackFull(int top)
{
    if (top == 9)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void push(int arr[], int x, int *top)
{
    if (stackFull(*top) == 1)
    {
        printf("error: stack overflow\n");
    }
    else
    {
        *top = *top + 1;
        arr[*top] = x;
    }
}

int pop(int arr[], int *top)
{
    if (stackEmpty(*top) == 1)
    {
        printf("error: stack underflow\n");
        return -1;
    }
    else
    {
        *top = *top - 1;
        return arr[*top + 1];
    }
}
// ポインタを利用しなければ，topの値が変わらない

// void main()
// {
//     int arr[10];
//     int top = 0;
//     for (int i = 1; i < 11; i++)
//     {
//         push(arr, i, &top);
//     }
//     for (int i = 1; i < 11; i++)
//     {
//         printf("%d\n", pop(arr, &top));
//     }
// }

// キューの実装
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

// void main()
// {
//     int arr[10];
//     int tail = 0;
//     int head = 0;
//     for (int i = 1; i < 12; i++)
//     {
//         enqueue(arr, i, &tail);
//     }

//     for (int i = 1; i < 12; i++)
//     {
//         printf("%d\n", dequeue(arr, &head));
//     }
// }
