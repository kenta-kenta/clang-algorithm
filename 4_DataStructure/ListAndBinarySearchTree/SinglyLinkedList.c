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

// Nodeを末尾に追加する
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

int stackEmpty(Node *head)
{
    return head == NULL;
}

void push(Node **head, int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}

int pop(Node **head)
{
    if (stackEmpty(*head))
    {
        printf("error: stack underflow\n");
        return -1;
    }
    else
    {
        int data = (*head)->data;
        Node *temp = *head;
        *head = (*head)->next;
        free(temp);
        return data;
    }
}

// void main()
// {
//     Node *head = NULL;

//     push(&head, 1);
//     push(&head, 2);
//     push(&head, 3);

//     printf("%d\n", pop(&head));
//     printf("%d\n", pop(&head));
//     printf("%d\n", pop(&head));
//     printf("%d\n", pop(&head));
// }

int queueEmpty(Node *head)
{
    return head == NULL;
}

void enqueue(Node **head, Node **tail, int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (*tail != NULL)
    {
        (*tail)->next = newNode;
    }

    *tail = newNode;

    if (*head == NULL)
    {
        *head = *tail;
    }
}

int dequeue(Node **head, Node **tail)
{
    if (queueEmpty(*head))
    {
        printf("error: queue underflow\n");
        return -1;
    }
    else
    {
        int data = (*head)->data;
        Node *temp = *head;
        *head = (*head)->next;
        free(temp);

        if (*head == NULL)
        {
            *tail = NULL;
        }

        return data;
    }
}

// void main()
// {
//     Node *head = NULL;
//     Node *tail = NULL;

//     enqueue(&head, &tail, 1);
//     enqueue(&head, &tail, 2);
//     enqueue(&head, &tail, 3);

//     printf("%d\n", dequeue(&head, &tail));
//     printf("%d\n", dequeue(&head, &tail));
//     printf("%d\n", dequeue(&head, &tail));
//     printf("%d\n", dequeue(&head, &tail));
// }