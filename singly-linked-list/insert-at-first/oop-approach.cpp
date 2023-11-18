#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = nullptr;
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
    void displayList()
    {
        if (!head) // if (head == nullptr)
            exit(1); // list is empty!
        Node *temp = head;
        while (temp) // while (temp != nullptr)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main()
{
    LinkedList l1;
    
    l1.insertAtBeginning(5); // 5
    l1.insertAtBeginning(4); // 4 5
    l1.insertAtBeginning(3); // 3 4 5
    l1.insertAtBeginning(2); // 2 3 4 5
    l1.insertAtBeginning(1); // 1 2 3 4 5

    l1.displayList(); // 1 2 3 4 5
    
    LinkedList l2;

    l2.insertAtBeginning(50); // 50
    l2.insertAtBeginning(40); // 40 50
    l2.insertAtBeginning(30); // 30 40 50
    
    l2.displayList(); // 30 40 50

    return 0;
}