#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *left = nullptr;
    Node *right = nullptr;
    Node(int data)
    {
        this->data = data;
    }
};

class BST
{
    Node *root = nullptr;

    void insertNode(Node *&root, int data)
    {
        if (!root) // if (root == nullptr)
            root = new Node(data);
        else if (data < root->data)
            insertNode(root->left, data);
        else
            insertNode(root->right, data);
    }

    bool searchNode(Node *root, int data)
    {
        if (!root)
            return false;
        else if (data == root->data)
            return true;
        else if (data < root->data)
            return searchNode(root->left, data);
        else
            return searchNode(root->right, data);
    }

public:
    void insert(int data)
    {
       insertNode(root, data);
    }

    bool search(int data)
    {
        return searchNode(root, data);
    }
};

int main()
{
    BST t1;

    t1.insert(10);
    t1.insert(7);
    t1.insert(15);
    t1.insert(5);

    cout << t1.search(15) << endl;
    cout << t1.search(1) << endl;
    cout << t1.search(10) << endl;
    cout << t1.search(6) << endl;
    return 0;
}