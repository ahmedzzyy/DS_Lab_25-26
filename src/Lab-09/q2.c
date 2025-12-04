#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
} Node;

Node *createNode(int data);
Node *insertNode(Node *root, int data);
void printTree(Node *root);

int main()
{
    Node *root = NULL;

    root = insertNode(root, 3);
    root = insertNode(root, 2);
    root = insertNode(root, 4);
    root = insertNode(root, 1);
    root = insertNode(root, 5);

    printf("Binary Tree (Level Traversal):\n");
    printTree(root);

    return 0;
}

Node *createNode(int data)
{
    Node *node = (Node *)malloc(sizeof(Node));
    if (node == NULL)
    {
        printf("Memory allocation failed\n");
        exit(1);
    }

    node->data = data;
    node->left = node->right = NULL;

    return node;
}

Node *insertNode(Node *root, int data)
{
    if (root == NULL)
    {
        return createNode(data);
    }

    // Recursive case: Insert data into the left or right subtree
    if (data < root->data)
    {
        root->left = insertNode(root->left, data);
    }
    else if (data > root->data)
    {
        root->right = insertNode(root->right, data);
    }

    return root;
}

void printTree(Node *root)
{
    if (root == NULL)
        return;

    Node **queue = (Node **)malloc(100 * sizeof(Node *));
    int front = 0, rear = 0;

    queue[rear++] = root;

    while (front < rear)
    {
        int levelCount = rear - front;

        for (int i = 0; i < levelCount; i++)
        {
            Node *current = queue[front++];

            printf("%d ", current->data);

            if (current->left)
                queue[rear++] = current->left;

            if (current->right)
                queue[rear++] = current->right;
        }

        printf("\n"); // Newline between levels
    }

    free(queue);
}
