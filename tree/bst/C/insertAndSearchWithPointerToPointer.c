#include <stdio.h>
#include <stdlib.h>

// define Node
typedef struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
} Node;

Node *getNode(int);
void insert(Node **, int);
void search(Node *, int);

int main()
{
    Node *t1 = NULL; // create a tree

    insert(&t1, 37);
    insert(&t1, 99);
    insert(&t1, 21);
    insert(&t1, 53);

    search(t1, 99); // true
    search(t1, 12); // false
    search(t1, 21); // true
    search(t1, 100); // false
    search(t1, 37); // true
    search(t1, 0); // false
    search(t1,53); // true
    search(t1,78); // false


    return 0;
}

Node *getNode(int data)
{
    // create node
    Node *newNode = malloc(sizeof (Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;

    // return the node
    return newNode;
}

void insert(Node **root, int data)
{
    if (!(*root)) // tree is empty or, root of sub-tree is referencing NULL
    {
        *root = getNode(data);
    }
    else if (data <= (*root)->data)
    {
        // insert at left sub-tree
        insert(&(*root)->left, data); // insert(root_of_left_sub_tree, data_to_be_inserted)
    }
    else
    {
        // insert at right sub-tree
        insert(&(*root)->right, data); // insert(root_of_right_sub_tree, data_to_be_inserted)
    }
}

void search(Node *root, int data)
{
    if (!root) // tree is empty or, root of sub-tree is referencing NULL
        printf("%d is not found.\n", data);
    else if (root->data == data) // if data is found in root
        printf("%d is found.\n", data);
    else if (data <= root->data)
        search(root->left, data); // search in left sub-tree
    else // data > root->data
        search(root->right, data); // search in right sub-tree
}
