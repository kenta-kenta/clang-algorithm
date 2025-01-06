#include <stdio.h>

#define M 13

int hash(int key, int index)
{
    return (key + index) % M;
}

int hashInsert(int arr[], int key)
{
    int index = 0;
    while (index < M)
    {
        int j = hash(key, index);
        if (arr[j] == NULL)
        {
            arr[j] = key;
            return j;
        }
        else
        {
            index++;
        }
    }
}

int hashSearch(int arr[], int key)
{
    int index = 0;

    while (index < M)
    {
        int j = hash(key, index);
        if (arr[j] == key)
        {
            return j;
        }
        else if (arr[j] == NULL)
        {
            return -1;
        }
        else
        {
            index++;
        }
    }
}

int hashDelete(int arr[], int key)
{
    int index = 0;

    while (index < M)
    {
        int j = hash(key, index);
        if (arr[j] == key)
        {
            arr[j] = NULL;
            return j;
        }
        else if (arr[j] == NULL)
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
    int arr[M] = {NULL};

    hashInsert(arr, 25);
    hashInsert(arr, 37);
    hashInsert(arr, 18);
    hashInsert(arr, 55);
    hashInsert(arr, 22);
    hashInsert(arr, 35);
    hashInsert(arr, 50);
    hashInsert(arr, 63);
    hashInsert(arr, 69);
    hashInsert(arr, 95);
    hashInsert(arr, 100);
    hashInsert(arr, 105);
    hashInsert(arr, 110);

    for (int i = 0; i < M; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    printf("Search 55: %d\n", hashSearch(arr, 55));
    printf("Search 100: %d\n", hashSearch(arr, 100));
    printf("Search 110: %d\n", hashSearch(arr, 110));
    printf("Search 111: %d\n", hashSearch(arr, 111));

    hashDelete(arr, 55);
    hashDelete(arr, 100);
    hashDelete(arr, 110);
    hashDelete(arr, 111);

    for (int i = 0; i < M; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}