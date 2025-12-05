#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
} Node;

Node *createNode(int data);
Node *insert(Node *root, int data);
void inorderTraversal(Node *root);
void preorderTraversal(Node *root);
void postorderTraversal(Node *root);
Node *search(Node *root, int key);
Node *deleteNode(Node *root, int key);
Node *findMin(Node *root);
Node *findMax(Node *root);

int main()
{
    Node *root = NULL;
    int choice, data, key;

    while (1)
    {
        printf("\n--- Binary Search Tree Operations ---\n");
        printf("1. Insert\n");
        printf("2. Inorder Traversal\n");
        printf("3. Preorder Traversal\n");
        printf("4. Postorder Traversal\n");
        printf("5. Search\n");
        printf("6. Delete\n");
        printf("7. Find Minimum\n");
        printf("8. Find Maximum\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter data to insert: ");
            scanf("%d", &data);

            root = insert(root, data);
            break;
        case 2:
            printf("Inorder Traversal: ");
            inorderTraversal(root);
            printf("\n");

            break;
        case 3:
            printf("Preorder Traversal: ");
            preorderTraversal(root);
            printf("\n");

            break;
        case 4:
            printf("Postorder Traversal: ");
            postorderTraversal(root);
            printf("\n");

            break;
        case 5:
            printf("Enter key to search: ");
            scanf("%d", &key);

            if (search(root, key))
                printf("Key %d found in the tree.\n", key);
            else
                printf("Key %d not found in the tree.\n", key);

            break;
        case 6:
            printf("Enter key to delete: ");
            scanf("%d", &key);

            root = deleteNode(root, key);
            break;
        case 7:
            Node *minNode = findMin(root);
            if (minNode)
                printf("Minimum element is %d\n", minNode->data);

            break;
        case 8:
            Node *maxNode = findMax(root);
            if (maxNode)
                printf("Maximum element is %d\n", maxNode->data);

            break;

        case 0:
            printf("Exiting...\n");
            exit(0);
        default:
            printf("Invalid choice! Please try again.\n");
        }
    }
}

Node *createNode(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (!newNode)
    {
        printf("Memory error\n");
        return NULL;
    }

    newNode->data = data;
    newNode->left = newNode->right = NULL;

    return newNode;
}

Node *insert(Node *root, int data)
{
    if (root == NULL)
        return createNode(data);

    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);

    return root;
}

void inorderTraversal(Node *root)
{
    if (!root)
        return;

    inorderTraversal(root->left);
    printf("%d ", root->data);
    inorderTraversal(root->right);
}

void preorderTraversal(Node *root)
{
    if (!root)
        return;

    printf("%d ", root->data);
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

void postorderTraversal(Node *root)
{
    if (!root)
        return;

    postorderTraversal(root->left);
    postorderTraversal(root->right);
    printf("%d ", root->data);
}

Node *search(Node *root, int key)
{
    if (root == NULL || root->data == key)
        return root;

    if (key < root->data)
        return search(root->left, key);
    else
        return search(root->right, key);
}

Node *deleteNode(Node *root, int key)
{
    if (root == NULL)
        return root;

    if (key < root->data)
        root->left = deleteNode(root->left, key);
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
    else
    {
        if (root->left == NULL)
        {
            Node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            Node *temp = root->left;
            free(root);
            return temp;
        }

        Node *temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }

    return root;
}

Node *findMin(Node *root)
{
    if (root == NULL)
    {
        printf("Tree is empty\n");
        return NULL;
    }

    while (root->left != NULL)
        root = root->left;

    return root;
}

Node *findMax(Node *root)
{
    if (root == NULL)
    {
        printf("Tree is empty\n");
        return NULL;
    }

    while (root->right != NULL)
        root = root->right;

    return root;
}