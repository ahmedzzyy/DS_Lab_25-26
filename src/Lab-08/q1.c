/*
Array-Based Queue Implementation:
1. Write a C program to simulate a printer queue where tasks arrive randomly and are processed in order.
i. Tasks (with a document ID and name) arrive at random (simulate using user input).
ii. Enqueue each print job.
iii. Dequeue in FIFO order to simulate printing
*/
#include <stdio.h>
#include <stdlib.h>

#define MAX 16

typedef struct
{
    int docID;
    char docName[50];
} PrintJob;

typedef struct
{
    PrintJob jobs[MAX];
    int front;
    int rear;
} Queue;

void initQueue(Queue *q);
int isFull(Queue *q);
int isEmpty(Queue *q);
void enqueue(Queue *q, PrintJob job);
PrintJob dequeue(Queue *q);

int main()
{
    Queue printerQueue;
    initQueue(&printerQueue);

    int choice;
    PrintJob job;

    while (1)
    {
        printf("\nPrinter Queue Menu:\n");
        printf("1. Add Print Job\n");
        printf("2. Process Print Job\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter Document ID: ");
            scanf("%d", &job.docID);
            printf("Enter Document Name: ");
            scanf("%s", job.docName);
            enqueue(&printerQueue, job);
            break;
        case 2:
            dequeue(&printerQueue);
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
    q->front = -1;
    q->rear = -1;
}

int isFull(Queue *q)
{
    return q->rear == MAX - 1;
}

int isEmpty(Queue *q)
{
    return q->front == -1;
}

void enqueue(Queue *q, PrintJob job)
{
    if (isFull(q))
    {
        printf("Queue is full. Cannot add more print jobs.\n");
        return;
    }
    if (isEmpty(q))
    {
        q->front = 0;
    }

    q->rear++;
    q->jobs[q->rear] = job;

    printf("Enqueued: Document ID %d, Name: %s\n", job.docID, job.docName);
}

PrintJob dequeue(Queue *q)
{
    PrintJob job;
    if (isEmpty(q))
    {
        printf("Queue is empty. No print jobs to process.\n");
        job.docID = -1; // Indicate no job
        return job;
    }

    job = q->jobs[q->front];
    q->front++;

    if (q->front > q->rear)
    {
        q->front = -1;
        q->rear = -1;
    }

    printf("Dequeued: Document ID %d, Name: %s\n", job.docID, job.docName);
    return job;
}