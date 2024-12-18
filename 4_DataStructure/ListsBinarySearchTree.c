#include <stdio.h>

// Singly Linked List
typedef struct Node
{
    int data;
    struct Node *next;
} Node;

Node head = {0, NULL};

void insert(int data)
{
    Node newNode = {data, NULL};
    for (Node p = head; p.next != NULL; p = *p.next)
    {
        if (p.next == NULL)
        {
            p.next = &newNode;
            break;
        }
    }
}