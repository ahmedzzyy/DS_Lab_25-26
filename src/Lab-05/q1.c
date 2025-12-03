#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
} Node;

Node *insertAtRear(Node *head, int data);
Node *deleteFromRear(Node *head);
Node *insertAtPosition(Node *head, int data, int pos);
Node *deleteFromPosition(Node *head, int pos);
Node *insertAfterElement(Node *head, int key, int data);
Node *insertBeforeElement(Node *head, int key, int data);
void traverse(Node *head);
void reverseTraverse(Node *head);

int main()
{
    Node *head = NULL;
    int choice, data, pos, key;

    while (1)
    {
        printf("\nMenu:\n");
        printf("1 - Insert an element at the rear end of the list\n");
        printf("2 - Delete an element from the rear end of the list\n");
        printf("3 - Insert an element at a given position of the list\n");
        printf("4 - Delete an element from a given position of the list\n");
        printf("5 - Insert an element after another element\n");
        printf("6 - Insert an element before another element\n");
        printf("7 - Traverse the list in forward direction\n");
        printf("8 - Traverse the list in reverse direction\n");
        printf("0 - Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the data to insert: ");
            scanf("%d", &data);

            head = insertAtRear(head, data);
            break;
        case 2:
            head = deleteFromRear(head);
            break;
        case 3:
            printf("Enter the position to insert: ");
            scanf("%d", &pos);

            printf("Enter the data to insert: ");
            scanf("%d", &data);

            head = insertAtPosition(head, data, pos);
            break;
        case 4:
            printf("Enter the position to delete: ");
            scanf("%d", &pos);

            head = deleteFromPosition(head, pos);
            break;
        case 5:
            printf("Enter the key element after which to insert: ");
            scanf("%d", &key);

            printf("Enter the data to insert: ");
            scanf("%d", &data);

            head = insertAfterElement(head, key, data);
            break;
        case 6:
            printf("Enter the key element before which to insert: ");
            scanf("%d", &key);

            printf("Enter the data to insert: ");
            scanf("%d", &data);

            head = insertBeforeElement(head, key, data);
            break;
        case 7:
            traverse(head);
            break;
        case 8:
            reverseTraverse(head);
            break;
        case 0:
            while (head != NULL)
            {
                head = deleteFromRear(head);
            }

            return 0;
        default:
            printf("Invalid choice\n");
        }
    }

    return 0;
}

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

Node *deleteFromRear(Node *head)
{
    if (head == NULL)
    {
        printf("List is empty\n");
        return head;
    }

    if (head->next == NULL)
    {
        free(head);
        head = NULL;
    }
    else
    {
        Node *temp = head;
        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }
        free(temp->next);
        temp->next = NULL;
    }
    return head;
}

Node *insertAtPosition(Node *head, int data, int pos)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;

    if (pos == 1)
    {
        newNode->next = head;
        if (head != NULL)
        {
            head->prev = newNode;
        }
        head = newNode;
        newNode->prev = NULL;
    }
    else
    {
        Node *temp = head;
        int i = 1;
        while (i < pos - 1 && temp != NULL)
        {
            temp = temp->next;
            i++;
        }

        if (temp == NULL)
        {
            printf("Position out of range\n");
            free(newNode);
            return head;
        }

        newNode->next = temp->next;
        newNode->prev = temp;

        if (temp->next != NULL)
        {
            temp->next->prev = newNode;
        }

        temp->next = newNode;
    }
    return head;
}

Node *deleteFromPosition(Node *head, int pos)
{
    if (head == NULL)
    {
        printf("List is empty\n");
        return head;
    }

    if (pos == 1)
    {
        Node *temp = head;
        head = head->next;
        if (head != NULL)
        {
            head->prev = NULL;
        }
        free(temp);
    }
    else
    {
        Node *temp = head;
        int i = 1;
        while (i < pos - 1 && temp != NULL)
        {
            temp = temp->next;
            i++;
        }

        if (temp == NULL || temp->next == NULL)
        {
            printf("Position out of range\n");
            return head;
        }

        Node *nodeToDelete = temp->next;
        temp->next = temp->next->next;

        if (temp->next != NULL)
        {
            temp->next->prev = temp;
        }

        free(nodeToDelete);
    }
    return head;
}

Node *insertAfterElement(Node *head, int key, int data)
{
    if (head == NULL)
    {
        printf("List is empty\n");
        return head;
    }

    Node *temp = head;
    while (temp != NULL && temp->data != key)
    {
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("Element not found\n");
        return head;
    }

    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = temp->next;
    newNode->prev = temp;

    if (temp->next != NULL)
    {
        temp->next->prev = newNode;
    }

    temp->next = newNode;
    return head;
}

Node *insertBeforeElement(Node *head, int key, int data)
{
    if (head == NULL)
    {
        printf("List is empty\n");
        return head;
    }

    if (head->data == key)
    {
        Node *newNode = (Node *)malloc(sizeof(Node));
        newNode->data = data;
        newNode->next = head;
        head->prev = newNode;
        newNode->prev = NULL;
        head = newNode;
        return head;
    }

    Node *temp = head;
    while (temp->next != NULL && temp->next->data != key)
    {
        temp = temp->next;
    }

    if (temp->next == NULL)
    {
        printf("Element not found\n");
        return head;
    }

    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = temp->next;
    newNode->prev = temp;
    temp->next->prev = newNode;
    temp->next = newNode;
    return head;
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

void reverseTraverse(Node *head)
{
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    printf("\nNULL");
    while (temp != NULL)
    {
        printf(" <- %d", temp->data);
        temp = temp->prev;
    }
    printf("\n");
}