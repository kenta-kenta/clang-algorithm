#include <stdio.h>

#define MAX 100

typedef struct
{
    char name;
    char password;
} Account;

int hash(char name, int index)
{
    return (name + index) % MAX;
}

int registerAccount(Account arr[], char name, char password)
{
    int index = 0;
    while (index < MAX)
    {
        int j = hash(name, index);
        if (arr[j].name == NULL)
        {
            arr[j].name = name;
            arr[j].password = password;
            return j;
        }
        else
        {
            index++;
        }
    }
}

int login(Account arr[], char name, char password)
{
    int index = 0;
    while (index < MAX)
    {
        int j = hash(name, index);
        if (arr[j].name == name && arr[j].password == password)
        {
            return j;
        }
        else if (arr[j].name == NULL)
        {
            return -1;
        }
        else
        {
            index++;
        }
    }
}

int deleteAccount(Account arr[], char name)
{
    int index = 0;
    while (index < MAX)
    {
        int j = hash(name, index);
        if (arr[j].name == name)
        {
            arr[j].name = NULL;
            arr[j].password = NULL;
            return j;
        }
        else if (arr[j].name == NULL)
        {
            return -1;
        }
        else
        {
            index++;
        }
    }
}

int main()
{
    Account arr[MAX];
    registerAccount(arr, 'a', '123');
    registerAccount(arr, 'b', '456');
    registerAccount(arr, 'c', '789');
    printf("%d\n", login(arr, 'a', '123'));
    printf("%d\n", login(arr, 'b', '456'));
    printf("%d\n", login(arr, 'c', '789'));
    printf("%d\n", login(arr, 'd', '123'));
    printf("%d\n", deleteAccount(arr, 'a'));
    printf("%d\n", login(arr, 'a', '123'));
    return 0;
}