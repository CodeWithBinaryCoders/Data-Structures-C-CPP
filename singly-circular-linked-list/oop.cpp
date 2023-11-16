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

class linkedList
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
    linkedList l;

    l.insertAtBeginning(2);
    l.insertAtBeginning(1);

    l.insertAtEnd(3);
    l.insertAtEnd(4);

    l.insert(10, 0);
    l.insert(20, 5);
    l.insert(30, 3);

    l.display();

    return 0;
}