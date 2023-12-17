#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next = nullptr;
    Node(int data)
    {
        this->data = data;
    }
};

class Stack
{
    Node *top = nullptr;

public:
    void push(int data)
    {
        Node *newNode = new Node(data);

        newNode->next = top;
        top = newNode;
    }

    void pop() // will not return the popped value
    {
        if (!top)
            cout << "Stack underflow!" << endl;
        else
        {
            Node *temp = top;
            top = top->next;
            delete temp;
        }
    }

    void peek()
    {
        if (!top)
            cout << "Stack empty" << endl;
        else
            cout << top->data << endl;
    }
};

int main()
{
    Stack s;

    s.push(3);
    s.push(2);
    s.push(1);

    s.pop();

    s.peek();

    return 0;
}