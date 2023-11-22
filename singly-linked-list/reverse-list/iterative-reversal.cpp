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
    Node *head = nullptr;

public:
    void insertAtBeginning(int data)
    {
        Node *newNode = new Node(data);

        newNode->next = head;
        head = newNode;
    }

    void reverseList()
    {
        Node *currentNode, *previousNode, *nextNode;

        currentNode = head;
        previousNode = nullptr;

        while (currentNode) // while (NULL != currentNode)
        {
            nextNode = currentNode->next;
            currentNode->next = previousNode;
            previousNode = currentNode;
            currentNode = nextNode;
        }

        head = previousNode;
    }

    void display()
    {
        Node *temp = head;

        while (temp) // while (NULL != temp)
        {
            cout << temp->data << ' ';
            temp = temp->next;
        }

        cout << endl;
    }
};

int main()
{
    LinkedList l;

    l.insertAtBeginning(3); // 3
    l.insertAtBeginning(2); // 2 3
    l.insertAtBeginning(1); // 1 2 3

    cout << "Origial list:" << endl;

    l.display(); // 1 2 3

    l.reverseList(); // 3 2 1

    cout << endl << "Reversed list:" << endl;
    l.display(); // 3 2 1

    return 0;
}