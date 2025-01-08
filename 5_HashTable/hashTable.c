#include <stdio.h>
#include <stdlib.h>

#define M 13

int hash(int key, int index)
{
    return (key + index) % M;
}
// チェイン法のハッシュ法
typedef struct node
{
    int data;
    struct node *next;
} Node;

// Nodeを出力する
void printList(Node *head)
{
    while (head != NULL)
    {
        printf("%d \n", head->data);
        head = head->next;
    }
}

// Nodeを先頭に追加する
void prepend(Node **head, int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = *head;
    if (*head != NULL)
    {
        newNode->next = *head;
    }
    *head = newNode;
}

// Nodeを削除する
void deleteNode(Node **head, int key)
{
    Node *temp = *head, *prev;

    if (temp != NULL && temp->data == key)
    {
        *head = temp->next;
        free(temp);
        return;
    }

    while (temp != NULL && temp->data != key)
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL)
        return;

    prev->next = temp->next;
    free(temp);
}

// Nodeを検索する
void search(Node *head, int key)
{
    Node *current = head;
    while (current != NULL)
    {
        if (current->data == key)
        {
            printf("Found %d\n", current->data);
            return;
        }
        current = current->next;
    }
    printf("Not Found\n");
}

int hashInsert(Node *arr[], int key)
{
    int j = key % M;
    prepend(&arr[j], key);
    return j;
}

int hashSearch(Node *arr[], int key)
{
    int j = key % M;
    search(arr[j], key);
    return j;
}

int hashDelete(Node *arr[], int key)
{
    int j = key % M;
    deleteNode(&arr[j], key);
    return j;
}

int main()
{
    Node *arr[M] = {NULL};

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
        printf("arr[%d]: ", i);
        printList(arr[i]);
    }

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
        printf("arr[%d]: ", i);
        printList(arr[i]);
    }

    return 0;
}

// オープンアドレス方式のハッシュ法
// int hashInsert(int arr[], int key)
// {
//     int index = 0;
//     while (index < M)
//     {
//         int j = hash(key, index);
//         if (arr[j] == NULL)
//         {
//             arr[j] = key;
//             return j;
//         }
//         else
//         {
//             index++;
//         }
//     }
// }

// int hashSearch(int arr[], int key)
// {
//     int index = 0;
//     while (index < M)
//     {
//         int j = hash(key, index);
//         if (arr[j] == key)
//         {
//             return j;
//         }
//         else if (arr[j] == NULL)
//         {
//             return -1;
//         }
//         else
//         {
//             index++;
//         }
//     }
// }

// int hashDelete(int arr[], int key)
// {
//     int index = 0;
//     while (index < M)
//     {
//         int j = hash(key, index);
//         if (arr[j] == key)
//         {
//             arr[j] = NULL;
//             return j;
//         }
//         else if (arr[j] == NULL)
//         {
//             return -1;
//         }
//         else
//         {
//             index++;
//         }
//     }
// }

// int main()
// {
//     int arr[M] = {NULL};
//     hashInsert(arr, 25);
//     hashInsert(arr, 37);
//     hashInsert(arr, 18);
//     hashInsert(arr, 55);
//     hashInsert(arr, 22);
//     hashInsert(arr, 35);
//     hashInsert(arr, 50);
//     hashInsert(arr, 63);
//     hashInsert(arr, 69);
//     hashInsert(arr, 95);
//     hashInsert(arr, 100);
//     hashInsert(arr, 105);
//     hashInsert(arr, 110);

//     for (int i = 0; i < M; i++)
//     {
//         printf("%d ", arr[i]);
//     }
//     printf("\n");

//     printf("Search 55: %d\n", hashSearch(arr, 55));
//     printf("Search 100: %d\n", hashSearch(arr, 100));
//     printf("Search 110: %d\n", hashSearch(arr, 110));
//     printf("Search 111: %d\n", hashSearch(arr, 111));

//     hashDelete(arr, 55);
//     hashDelete(arr, 100);
//     hashDelete(arr, 110);
//     hashDelete(arr, 111);

//     for (int i = 0; i < M; i++)
//     {
//         printf("%d ", arr[i]);
//     }
//     printf("\n");

//     return 0;
// }
