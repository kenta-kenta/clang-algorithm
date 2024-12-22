#include <stdio.h>

// スタックの実装
// 空のスタックを作成
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

// スタックが満杯かどうかを判定
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

// スタックに要素を追加
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

// スタックから要素を取り出す
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

void main()
{
    int arr[10];
    int top = 0;
    for (int i = 1; i < 11; i++)
    {
        push(arr, i, &top);
    }
    for (int i = 1; i < 11; i++)
    {
        printf("%d\n", pop(arr, &top));
    }
}