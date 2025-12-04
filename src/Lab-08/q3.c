/*
Linked List-Based Queue Implementation:
3. Implement a queue using a singly linked list with enqueue and dequeue operations.
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

typedef struct
{
    Node *front;
    Node *rear;
} Queue;

void initQueue(Queue *q);
int isEmpty(Queue *q);
void enqueue(Queue *q, int value);
int dequeue(Queue *q);

int main()
{
    Queue queue;
    initQueue(&queue);

    int choice, value;

    while (1)
    {
        printf("\nLinked List Queue Menu:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter value to enqueue: ");
            scanf("%d", &value);
            enqueue(&queue, value);
            break;
        case 2:
            if (isEmpty(&queue))
            {
                printf("Queue is empty. Cannot dequeue.\n");
            }
            else
            {
                value = dequeue(&queue);
                printf("Dequeued: %d\n", value);
            }
            break;
        case 0:
            exit(0);
        default:
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

void initQueue(Queue *q)
{
    q->front = NULL;
    q->rear = NULL;
}

int isEmpty(Queue *q)
{
    return q->front == NULL;
}

void enqueue(Queue *q, int value)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL)
    {
        printf("Memory allocation failed. Cannot enqueue.\n");
        return;
    }

    newNode->data = value;
    newNode->next = NULL;

    if (q->rear == NULL)
    {
        q->front = newNode;
        q->rear = newNode;
    }
    else
    {
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

int dequeue(Queue *q)
{
    if (isEmpty(q))
    {
        printf("Queue is empty. Cannot dequeue.\n");
        return -1;
    }

    Node *temp = q->front;
    int value = temp->data;

    q->front = q->front->next;
    if (q->front == NULL)
    {
        // Queue is empty
        q->rear = NULL;
    }

    free(temp);
    return value;
}