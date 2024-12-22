#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int key;
    struct node *parent;
    struct node *left;
    struct node *right;
} Node;

void printTree(Node *tree)
{
    if (tree == NULL)
    {
        return;
    }

    printf("%d\n", tree->key);
    printTree(tree->left);
    printTree(tree->right);
}

void insert(Node **tree, int key)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->key = key;
    newNode->parent = NULL;
    newNode->left = NULL;
    newNode->right = NULL;

    Node *y = NULL;
    Node *x = *tree;

    while (x != NULL)
    {
        y = x;
        if (newNode->key < x->key)
        {
            x = x->left;
        }
        else
        {
            x = x->right;
        }
    }

    newNode->parent = y;
    if (y == NULL)
    {
        *tree = newNode;
    }
    else if (newNode->key < y->key)
    {
        y->left = newNode;
    }
    else
    {
        y->right = newNode;
    }
}

void delete(Node **tree, int key)
{
    Node *z = *tree;
    while (z != NULL && z->key != key)
    {
        if (key < z->key)
        {
            z = z->left;
        }
        else
        {
            z = z->right;
        }
    }

    if (z == NULL)
    {
        return;
    }

    Node *x;
    Node *y;
    if (z->left == NULL || z->right == NULL)
    {
        y = z;
    }
    else
    {
        y = z->right;
        while (y->left != NULL)
        {
            y = y->left;
        }
    }

    if (y->left != NULL)
    {
        x = y->left;
    }
    else
    {
        x = y->right;
    }

    if (x != NULL)
    {
        x->parent = y->parent;
    }

    if (y->parent == NULL)
    {
        *tree = x;
    }
    else if (y == y->parent->left)
    {
        y->parent->left = x;
    }
    else
    {
        y->parent->right = x;
    }

    if (y != z)
    {
        z->key = y->key;
    }

    free(y);
}

void search(Node *tree, int key)
{
    Node *current = tree;
    while (current != NULL)
    {
        if (current->key == key)
        {
            printf("Found %d\n", current->key);
            return;
        }
        else if (key < current->key)
        {
            current = current->left;
        }
        else
        {
            current = current->right;
        }
    }
    printf("Not found\n");
}

void main()
{
    Node *tree = NULL;

    insert(&tree, 9);
    insert(&tree, 3);
    insert(&tree, 5);
    insert(&tree, 8);
    insert(&tree, 1);
    insert(&tree, 4);
    insert(&tree, 7);

    printTree(tree);

    search(tree, 3);
    search(tree, 6);

    delete (&tree, 3);
    search(tree, 3);
}