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
void inorderTraversal(Node *root);
void preorderTraversal(Node *root);
void postorderTraversal(Node *root);
void printParent(Node *root, int data);
int treeDepth(Node *root);
int printAncestors(Node *root, int data);
int countLeafNodes(Node *root);

int main()
{
    Node *root = NULL;

    root = insertNode(root, 3);
    root = insertNode(root, 2);
    root = insertNode(root, 4);
    root = insertNode(root, 1);
    root = insertNode(root, 5);

    printf("Inorder Traversal: ");
    inorderTraversal(root);
    printf("\n");

    printf("Preorder Traversal: ");
    preorderTraversal(root);
    printf("\n");

    printf("Postorder Traversal: ");
    postorderTraversal(root);
    printf("\n");

    printf("Parent of 5 is: ");
    printParent(root, 5);
    printf("\n");

    printf("Depth of the tree is %d\n", treeDepth(root));
    printf("\n");

    printf("Ancestors of 5 are: ");
    printAncestors(root, 5);
    printf("\n");

    printf("Number of leaf nodes is %d\n", countLeafNodes(root));

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

void inorderTraversal(Node *root)
{
    if (root == NULL)
        return;

    inorderTraversal(root->left);
    printf("%d ", root->data);
    inorderTraversal(root->right);
}

void preorderTraversal(Node *root)
{
    if (root == NULL)
        return;

    printf("%d ", root->data);
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

void postorderTraversal(Node *root)
{
    if (root == NULL)
        return;

    postorderTraversal(root->left);
    postorderTraversal(root->right);
    printf("%d ", root->data);
}

void printParent(Node *root, int data)
{
    if (root == NULL)
        return;

    if ((root->left && root->left->data == data) || (root->right && root->right->data == data))
    {
        printf("Parent of %d is %d\n", data, root->data);
        return;
    }

    printParent(root->left, data);
    printParent(root->right, data);
}

int treeDepth(Node *root)
{
    if (root == NULL)
        return 0;

    int leftDepth = treeDepth(root->left);
    int rightDepth = treeDepth(root->right);

    return (leftDepth > rightDepth ? leftDepth : rightDepth) + 1; // max (leftDepth, rightDepth) + 1)
}

int printAncestors(Node *root, int data)
{
    if (root == NULL)
        return 0;

    if (root->data == data)
        return 1;

    if (printAncestors(root->left, data) || printAncestors(root->right, data))
    {
        printf("%d ", root->data);
        return 1;
    }

    return 0;
}

int countLeafNodes(Node *root)
{
    if (root == NULL)
        return 0;
    if (root->left == NULL && root->right == NULL)
        return 1;

    return countLeafNodes(root->left) + countLeafNodes(root->right);
}