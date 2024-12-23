#include <stdio.h>
#include <stdlib.h>

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

// Singly Linked Listの操作
void main()
{
    Node *head = NULL;

    prepend(&head, 3);
    prepend(&head, 2);
    prepend(&head, 1);

    deleteNode(&head, 2);

    printList(head);
    search(head, 1);
}
