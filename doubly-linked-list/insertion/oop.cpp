#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next = nullptr;
    Node *prev = nullptr;
    Node(int data)
    {
        this->data = data;
    }
};

class LinkedList
{
    Node *head = nullptr, *tail = nullptr;
    int countNode = 0;

public:
    void insertAtFirst(int data)
    {
        Node *newNode = new Node(data);

        if (!head && !tail) // empty list
            head = tail = newNode;

        else
        {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }

        countNode++;
    }

    void insertAtLast(int data)
    {
        Node *newNode = new Node(data);

        if (!head && !tail) // empty list
            head = tail = newNode;

        else
        {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }

        countNode++;
    }

    void insertAtPosition(int position, int data)
    {
        if (position < 0 || position > countNode)
            exit(2);

        else if (position == 0)
            insertAtFirst(data);

        else if (position == countNode)
            insertAtLast(data);

        else
        {
            Node *newNode = new Node(data);

            Node *temp = head;

            for (int i = 0; i < position - 1; i++)
                temp = temp->next;

            newNode->prev = temp;
            newNode->next = temp->next;
            temp->next = newNode;
            newNode->next->prev = newNode;
            countNode++;
        }
    }

    void forwardDisplay()
    {
        Node *temp = head;

        if (!head && !tail)
        {
            cout << "Empty list!" << endl;
            return;
        }

        else
        {
            while (temp) // while (temp != nullptr)
            {
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << endl;
        }
    }

    void reverseDisplay()
    {
        Node *temp = tail;

        if (!head && !tail)
        {
            cout << "Empty list!" << endl;
            return;
        }

        else
        {
            while (temp) // while (temp != nullptr)
            {
                cout << temp->data << " ";
                temp = temp->prev;
            }
            cout << endl;
        }
    }
};

int main()
{
    LinkedList l1;

    l1.insertAtLast(2); // 2
    l1.insertAtLast(3); // 2 3
    l1.insertAtLast(4); // 2 3 4
    l1.insertAtLast(5); // 2 3 4 5

    l1.insertAtFirst(1); // 1 2 3 4 5

    l1.forwardDisplay(); // 1 2 3 4 5
    l1.reverseDisplay(); // 5 4 3 2 1

    l1.insertAtPosition(0, 0); // 0 1 2 3 4 5
    
    l1.forwardDisplay();

    l1.insertAtPosition(6, 6); // 0 1 2 3 4 5 6
    
    l1.forwardDisplay();

    l1.insertAtPosition(4, 404); // 0 1 2 3 404 4 5 6
    
    l1.forwardDisplay(); // 0 1 2 3 404 4 5 6
    l1.reverseDisplay(); // 6 5 4 404 3 2 1 0
    
    return 0;
}