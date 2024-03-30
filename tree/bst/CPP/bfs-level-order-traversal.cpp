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

    void performLevelOrderTraversal(Node *root)
    {
        if (!root)
            return;

        queue<Node *> q;

        q.push(root);

        while (!q.empty())
        {
            Node *current = q.front();
            cout << current->data << " ";

            if (current->left)
                q.push(current->left);

            if (current->right)
                q.push(current->right);

            q.pop();
        }
        cout << endl;
    }

public:
    void insert(int data)
    {
        insertNodeBST(root, data);
    }

    void levelOrderTraversal()
    {
        performLevelOrderTraversal(root);
    }
};
int main()
{
    BST t;
    t.insert(10);
    t.insert(5);
    t.insert(15);
    t.insert(3);
    t.insert(7);
    t.insert(12);
    t.insert(17);

    t.levelOrderTraversal();

    return 0;
}