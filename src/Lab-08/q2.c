/*
Array-Based Queue Implementation:
2. Write a C program to implement a circular queue using arrays.
*/
#include <stdio.h>
#include <stdlib.h>

#define MAX 16

typedef struct
{
    int data[MAX];
    int front;
    int rear;
} CircularQueue;

void initQueue(CircularQueue *q);
int isFull(CircularQueue *q);
int isEmpty(CircularQueue *q);
void enqueue(CircularQueue *q, int value);
int dequeue(CircularQueue *q);

int main()
{
    CircularQueue queue;
    initQueue(&queue);

    int choice, value;

    while (1)
    {
        printf("\nCircular Queue Menu:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            if (isFull(&queue))
            {
                printf("Queue is full. Cannot enqueue.\n");
            }
            else
            {
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                enqueue(&queue, value);
            }
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

void initQueue(CircularQueue *q)
{
    q->front = -1;
    q->rear = -1;
}

int isFull(CircularQueue *q)
{
    return (q->rear + 1) % MAX == q->front;
}

int isEmpty(CircularQueue *q)
{
    return q->front == -1;
}

void enqueue(CircularQueue *q, int value)
{
    if (isFull(q))
    {
        printf("Queue is full. Cannot enqueue %d.\n", value);
        return;
    }
    if (isEmpty(q))
    {
        q->front = 0;
    }

    q->rear = (q->rear + 1) % MAX;
    q->data[q->rear] = value;

    printf("Enqueued: %d\n", value);
}

int dequeue(CircularQueue *q)
{
    if (isEmpty(q))
    {
        printf("Queue is empty. Cannot dequeue.\n");
        return -1;
    }

    int value = q->data[q->front];
    if (q->front == q->rear)
    {
        // Queue is empty
        q->front = -1;
        q->rear = -1;
    }
    else
    {
        q->front = (q->front + 1) % MAX;
    }

    return value;
}