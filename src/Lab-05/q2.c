#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
} Node;

Node *insertAtRear(Node *head, int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;

    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        Node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
    return head;
}

Node *concatenateLists(Node *X1, Node *X2)
{
    if (X1 == NULL)
    {
        return X2;
    }

    if (X2 == NULL)
    {
        return X1;
    }

    // Find the last node of X1
    Node *lastNodeX1 = X1;
    while (lastNodeX1->next != NULL)
    {
        lastNodeX1 = lastNodeX1->next;
    }

    lastNodeX1->next = X2;
    X2->prev = lastNodeX1;

    return X1;
}

void traverse(Node *head)
{
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    Node *temp = head;
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main()
{
    Node *X1 = NULL;
    Node *X2 = NULL;

    X1 = insertAtRear(X1, 1);
    X1 = insertAtRear(X1, 2);
    X1 = insertAtRear(X1, 3);

    X2 = insertAtRear(X2, 4);
    X2 = insertAtRear(X2, 5);
    X2 = insertAtRear(X2, 6);

    printf("List X1: \n");
    traverse(X1);

    printf("List X2: \n");
    traverse(X2);

    // Concatenate the lists
    X1 = concatenateLists(X1, X2);

    printf("Concatenated List: \n");
    traverse(X1);

    return 0;
}