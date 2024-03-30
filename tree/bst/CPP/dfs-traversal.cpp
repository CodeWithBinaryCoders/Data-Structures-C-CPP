#include <iostream>
#include <queue>
using namespace std;
class Node
{
public:
    int data;
    Node *left, *right;
    Node(int data)
    {
        this->data = data;
        this->left = this->right = nullptr;
    }
};
class BST
{
    Node *root = nullptr;
    void insertNodeBST(Node *&root, int data)
    {
        if (!root)
            root = new Node(data);
        else if (data <= root->data)
            insertNodeBST(root->left, data);
        else
            insertNodeBST(root->right, data);
    }
    void preorder(Node *root)
    {
        if (!root)
            return;
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }
    void inorder(Node *root)
    {
        if (!root)
            return;
        preorder(root->left);
        cout << root->data << " ";
        preorder(root->right);
    }
    void postorder(Node *root)
    {
        if (!root)
            return;
        preorder(root->left);
        preorder(root->right);
        cout << root->data << " ";
    }

public:
    void insert(int data)
    {
        insertNodeBST(root, data);
    }
    void dfsTraversal()
    {
        cout << "Preorder : ";
        preorder(root);
        cout << endl;
        cout << "Inorder : ";
        inorder(root);
        cout << endl;
        cout << "Postorder : ";
        postorder(root);
        cout << endl;
    }
};
int main()
{
    BST t;
    t.insert(5);
    t.insert(3);
    t.insert(8);
    t.insert(2);
    t.dfsTraversal();
    return 0;
}