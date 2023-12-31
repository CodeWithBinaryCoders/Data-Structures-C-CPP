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

class LinkedList
{
    Node *tail = nullptr;
    int count = 0;

public:
    void insertAtBeginning(int data)
    {
        Node *newNode = new Node(data);

        if (!tail) // is list is empty
        {
            tail = newNode;
            newNode->next = newNode;
        }
        else
        {
            newNode->next = tail->next;
            tail->next = newNode;
        }

        count++;
    }

    void insertAtEnd(int data)
    {
        Node *newNode = new Node(data);

        if (!tail)
        {
            tail = newNode;
            newNode->next = newNode;
        }
        else
        {
            newNode->next = tail->next;
            tail->next = newNode;
            tail = newNode;
        }

        count++;
    }

    void insert(int data, int position)
    {
        if (position < 0 || position > count)
            exit(1);

        if (!position)
        {
            insertAtBeginning(data);
            return;
        }

        if (position == count)
        {
            insertAtEnd(data);
            return;
        }

        Node *temp = tail;
        int i = 0;

        while (i < position)
        {
            temp = temp->next;
            i++;
        }

        Node *newNode = new Node(data);

        newNode->next =  temp->next;
        temp->next = newNode;

        count++;
    }

    void display()
    {
        if (!tail)
        {
            cout << "No data" << endl;
            return;
        }

        Node *temp = tail->next;

        do
        {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != tail->next);

        cout << endl;
    }
};

int main()
{
    LinkedList l;

    l.insertAtBeginning(2); // 2
    l.insertAtBeginning(1); // 1 2

    l.insertAtEnd(3); // 1 2 3
    l.insertAtEnd(4); // 1 2 3 4

    l.insert(10, 0); // 10 1 2 3 4
    l.insert(20, 5); // 10 1 2 3 4 20
    l.insert(30, 3); // 10 1 2 30 3 4 20

    l.display(); // 10 1 2 30 3 4 20

    return 0;
}