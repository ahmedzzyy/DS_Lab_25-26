#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

Node *insertAtBeginning(Node *head, int new_data);
void insertAfter(struct Node *prev_node, int new_data);
Node *insertBefore(Node *head, Node *prev_node, int new_data);
Node *deleteNode(Node *head, int key);
void traverse(Node *head);
Node *reverse(Node *head);
Node *sort(Node *head);
Node *deleteAlternateNodes(Node *head);
Node *insertInSorted(Node *head, int new_data);

int main()
{
    Node *head = NULL;

    int choice;
    while (1)
    {
        printf("\nLinked List Menu:\n");
        printf("1. Insert at beginning\n");
        printf("2. Insert after a node\n");
        printf("3. Insert before a node\n");
        printf("4. Delete a node\n");
        printf("5. Traverse the list\n");
        printf("6. Reverse the list\n");
        printf("7. Sort the list\n");
        printf("8. Delete every alternate node\n");
        printf("9. Insert in a sorted list\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
        {
            int data;
            printf("Enter the data to insert at the beginning: ");
            scanf("%d", &data);

            head = insertAtBeginning(head, data);
            break;
        }
        case 2:
        {
            int data;
            printf("Enter the data to insert after a node: ");
            scanf("%d", &data);

            if (head == NULL)
            {
                printf("List is empty. Cannot insert after a node.\n");
                break;
            }

            printf("Enter the data of the node after which to insert: ");
            int key;
            scanf("%d", &key);

            struct Node *temp = head;
            while (temp != NULL && temp->data != key)
            {
                temp = temp->next;
            }
            if (temp == NULL)
            {
                printf("Node not found.\n");
                break;
            }

            insertAfter(temp, data);
            break;
        }
        case 3:
        {
            int data;
            printf("Enter the data to insert before a node: ");
            scanf("%d", &data);

            if (head == NULL)
            {
                printf("List is empty. Cannot insert before a node.\n");
                break;
            }

            printf("Enter the data of the node before which to insert: ");
            int key;
            scanf("%d", &key);

            struct Node *temp = head;
            while (temp != NULL && temp->data != key)
            {
                temp = temp->next;
            }
            if (temp == NULL)
            {
                printf("Node not found.\n");
                break;
            }

            head = insertBefore(head, temp, data);
            break;
        }
        case 4:
        {
            if (head == NULL)
            {
                printf("List is empty. Cannot delete a node.\n");
                break;
            }

            printf("Enter the data of the node to delete: ");
            int key;
            scanf("%d", &key);

            head = deleteNode(head, key);
            break;
        }
        case 5:
            traverse(head);
            break;
        case 6:
            head = reverse(head);
            break;
        case 7:
            head = sort(head);
            break;
        case 8:
            head = deleteAlternateNodes(head);
            break;
        case 9:
        {
            int data;
            printf("Enter the data to insert in a sorted list: ");
            scanf("%d", &data);

            head = insertInSorted(head, data);
            break;
        }
        case 0:
            Node *temp;
            while (head != NULL)
            {
                temp = head;
                head = head->next;
                free(temp);
            }

            return 0;
        default:
            printf("Invalid choice. Please choose a valid option.\n");
        }
    }

    return 0;
}

Node *insertAtBeginning(Node *head, int new_data)
{
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->data = new_data;
    new_node->next = head;
    head = new_node;

    return head;
}

void insertAfter(struct Node *prev_node, int new_data)
{
    if (prev_node == NULL)
    {
        printf("The given previous node cannot be NULL\n");
        return;
    }

    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->data = new_data;
    new_node->next = prev_node->next;
    prev_node->next = new_node;
}

Node *insertBefore(Node *head, Node *prev_node, int new_data)
{
    if (prev_node == NULL)
    {
        printf("The given previous node cannot be NULL\n");
        return NULL;
    }

    if (head == prev_node)
    {
        head = insertAtBeginning(head, new_data);
        return head;
    }

    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->data = new_data;
    new_node->next = prev_node;

    Node *temp = head;
    while (temp->next != prev_node && temp->next != NULL)
    {
        temp = temp->next;
    }

    if (temp->next == NULL)
    {
        printf("The given previous node is not present in the list\n");
        free(new_node);
        return head;
    }

    temp->next = new_node;
    return head;
}

Node *deleteNode(Node *head, int key)
{
    if (head == NULL)
        return NULL;

    if (head->data == key)
    {
        Node *temp = head;
        head = head->next;
        free(temp);
        return head;
    }

    Node *temp = head;
    while (temp->next != NULL && temp->next->data != key)
    {
        temp = temp->next;
    }

    if (temp->next == NULL)
        return head;

    Node *nodeToDelete = temp->next;
    temp->next = temp->next->next;
    free(nodeToDelete);

    return head;
}

void traverse(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

Node *reverse(Node *head)
{
    Node *prev = NULL;
    Node *current = head;
    Node *next = NULL;

    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;

    return head;
}

Node *sort(Node *head)
{
    int swapped;
    Node *currentNode;

    if (head == NULL)
        return NULL;

    do
    {
        swapped = 0;
        currentNode = head;

        while (currentNode->next != NULL)
        {
            if (currentNode->data > currentNode->next->data)
            {
                int temp = currentNode->data;
                currentNode->data = currentNode->next->data;
                currentNode->next->data = temp;
                swapped = 1;
            }
            currentNode = currentNode->next;
        }
    } while (swapped);

    return head;
}

Node *deleteAlternateNodes(Node *head)
{
    if (head == NULL || head->next == NULL)
        return head;

    Node *current = head;
    Node *next = NULL;

    while (current != NULL && current->next != NULL)
    {
        next = current->next;
        current->next = next->next;
        free(next);
        current = current->next;
    }

    return head;
}

Node *insertInSorted(Node *head, int new_data)
{
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->data = new_data;

    if (head == NULL || head->data >= new_data)
    {
        new_node->next = head;
        head = new_node;
        return head;
    }

    Node *current = head;
    while (current->next != NULL && current->next->data < new_data)
    {
        current = current->next;
    }

    new_node->next = current->next;
    current->next = new_node;

    return head;
}