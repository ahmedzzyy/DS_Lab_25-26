/*
Linked List-Based Queue Implementation:
4. Create a queue of structures (e.g., queue of patients with name, age, and priority).
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct Patient
{
    char name[50];
    int age;
    int priority;
} Patient;

typedef struct Node
{
    Patient data;
    struct Node *next;
} Node;

typedef struct
{
    Node *front;
    Node *rear;
} Queue;

void initQueue(Queue *q);
int isEmpty(Queue *q);
void enqueue(Queue *q, Patient value);
Patient dequeue(Queue *q);

int main()
{
    Queue queue;
    initQueue(&queue);

    int choice;
    Patient patient;

    while (1)
    {
        printf("\nPatient Queue Menu:\n");
        printf("1. Enqueue Patient\n");
        printf("2. Dequeue Patient\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter patient name: ");
            scanf("%s", patient.name);
            printf("Enter patient age: ");
            scanf("%d", &patient.age);
            printf("Enter patient priority: ");
            scanf("%d", &patient.priority);

            enqueue(&queue, patient);
            break;
        case 2:
            if (isEmpty(&queue))
            {
                printf("Queue is empty. Cannot dequeue.\n");
            }
            else
            {
                patient = dequeue(&queue);
                printf("Dequeued Patient: Name: %s, Age: %d, Priority: %d\n", patient.name, patient.age, patient.priority);
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

void enqueue(Queue *q, Patient value)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL)
    {
        printf("Memory allocation failed.\n");
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

Patient dequeue(Queue *q)
{
    if (isEmpty(q))
    {
        printf("Queue is empty. Cannot dequeue.\n");
        printf("Exiting...\n");
        exit(1);
    }

    Node *temp = q->front;
    Patient value = temp->data;

    q->front = q->front->next;
    if (q->front == NULL)
    {
        // Queue is empty
        q->rear = NULL;
    }

    free(temp);
    return value;
}