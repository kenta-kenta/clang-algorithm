#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} Node;

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