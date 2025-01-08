#include <stdio.h>

#define MAX 100

int hash(int password)
{
    return password % MAX;
}

int registerAccount(char arr[], char name, int password)
{
    int j = hash(password);
    if (arr[j] == '\0') // NULLの代わりに'\0'を使用
    {
        arr[j] = name;
        return j;
    }
    else
    {
        printf("パスワードを変更してください\n");
        return -1;
    }
}

int login(char arr[], char name, int password)
{
    int j = hash(password);
    if (arr[j] == name)
    {
        return j;
    }
    else if (arr[j] == '\0') // NULLの代わりに'\0'を使用
    {
        printf("アカウントが存在しません\n");
        return -1;
    }
    else
    {
        printf("パスワードが違います\n");
        return -1;
    }
}

int main()
{
    char arr[MAX];
    // 配列を初期化
    for (int i = 0; i < MAX; i++)
    {
        arr[i] = '\0'; // NULL文字で初期化
    }

    registerAccount(arr, 'C', 9012);
    registerAccount(arr, 'A', 1234);
    registerAccount(arr, 'B', 5678);
    printf("%d\n", hash(9012));
    printf("%d\n", login(arr, 'C', 9012));
    printf("%d\n", login(arr, 'A', 1234));
    printf("%d\n", login(arr, 'B', 5678));
    printf("%d\n", login(arr, 'D', 3456));
    return 0;
}