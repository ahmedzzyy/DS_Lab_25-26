#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

Node *createNode(int data);
void insertEnd(Node **first, Node **last, int data);
void deleteBeginning(Node **first, Node **last);
void deleteEnd(Node **first, Node **last);
void traverse(Node *first, Node *last);

int main()
{
    Node *first = NULL, *last = NULL;
    int choice, data;

    while (1)
    {
        printf("\nCircular Singly Linked List Operations:\n");
        printf("1 - Insert at End\n");
        printf("2 - Delete from Beginning\n");
        printf("3 - Delete from End\n");
        printf("4 - Display List\n");
        printf("0 - Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter data to insert: ");
            scanf("%d", &data);

            insertEnd(&first, &last, data);

            traverse(first, last);
            break;
        case 2:
            if (first == NULL)
            {
                printf("List is empty. Cannot delete.\n");
                break;
            }

            deleteBeginning(&first, &last);

            traverse(first, last);
            break;
        case 3:
            if (first == NULL)
            {
                printf("List is empty. Cannot delete.\n");
                break;
            }

            deleteEnd(&first, &last);
            traverse(first, last);
            break;
        case 4:
            traverse(first, last);
            break;
        case 0:
            while (first != NULL)
                deleteBeginning(&first, &last);
            exit(0);
            break;
        default:
            printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}

Node *createNode(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL)
    {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertEnd(Node **first, Node **last, int data)
{
    Node *newNode = createNode(data);
    if (*first == NULL)
    {
        *first = newNode;
        *last = newNode;
        newNode->next = *first;
    }
    else
    {
        (*last)->next = newNode;
        newNode->next = *first;
        *last = newNode;
    }
}

void deleteBeginning(Node **first, Node **last)
{
    if (*first == *last)
    {
        free(*first);
        *first = NULL;
        *last = NULL;
        return;
    }

    Node *temp = *first;
    *first = (*first)->next;
    (*last)->next = *first;

    free(temp);
}

void deleteEnd(Node **first, Node **last)
{
    if (*first == *last)
    {
        free(*first);
        *first = NULL;
        *last = NULL;
        return;
    }

    Node *current = *first;
    while (current->next != *last)
    {
        current = current->next;
    }

    current->next = *first;
    free(*last);
    *last = current;
}

void traverse(Node *first, Node *last)
{
    if (first == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    Node *current = first;
    do
    {
        printf("%d -> ", current->data);
        current = current->next;
    } while (current != first);

    printf("(back to first)\n");
}