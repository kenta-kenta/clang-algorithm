#include <stdio.h>

#define M 13

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

int main()
{
}