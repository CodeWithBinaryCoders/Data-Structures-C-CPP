#include <stdio.h>
#include <stdlib.h>

// define Node
typedef struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

} Node;

Node *root = NULL; // initially empty root

Node *createNode(int);
Node *insert(Node *, int);
void search(Node *, int);

int main(void)
{
    root = insert(root, 5);
    root = insert(root, 7);
    root = insert(root, 4);
    root = insert(root, 1);
    root = insert(root, 2);
    root = insert(root, 6);
    root = insert(root, 8);

    search(root, 5); // true
    search(root, 7); // true
    search(root, 4); // true
    search(root, 1); // true
    search(root, 2); // true
    search(root, 6); // true
    search(root, 8); // true

    search(root, 12); // false
    search(root, 16); // false
    search(root, 18); // false

    return 0;
}

Node *createNode(int data)
{
    Node *newNode = malloc(sizeof(Node));

    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

Node *insert(Node *root, int data)
{
    if (!root) // if (NULL == root)
        return createNode(data);

    if (data <= root->data)
        root->left = insert(root->left, data);
    else
        root->right = insert(root->right, data);

    return root;
}

void search(Node *root, int data)
{
    if (!root)
        printf("%d is not found.\n", data);
    else if (data == root->data)
        printf("%d is found.\n", data);
    else if (data <= root->data)
        search(root->left, data);
    else
        search(root->right, data);
}