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
    Node *head = nullptr, *tail = nullptr;
    int countNode = 0;

public:
    void insertAtFirst(int data)
    {
        Node *newNode = new Node(data);
        if (!countNode) // if (countNode == 0)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            newNode->next = head;
            head = newNode;
        }
        countNode++;
    }

    void insertAtLast(int data)
    {
        Node *newNode = new Node(data);
        if (!countNode) // if (countNode == 0)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
        countNode++;
    }

    void insertAtPosition(int position, int data)
    {
        if (position < 0 || position > countNode) // not a valid position
            exit(1);                              // exit from the program directly
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
            newNode->next = temp->next;
            temp->next = newNode;
            countNode++;
        }
    }

    void deleteFromFirst()
    {
        if (!head) // if (head == NULL)
            exit(2);

        Node *temp = head;
        head = head->next;
        delete temp;

        if (countNode == 1)
            tail = NULL;

        countNode--;
    }

    void deleteFromLast()
    {
        if (!head) // if (head == NULL)
            exit(3);
        else if (countNode == 1)
        {
            delete head;
            head = NULL;
            tail = NULL;
        }
        else
        {
            Node *temp = head;

            while (temp->next != tail)
                temp = temp->next;

            temp->next = NULL;
            delete tail;
            tail = temp;
        }
        countNode--;
    }

    void deleteFromAny(int position)
    {
        if (!head)
            exit(4);

        if (position < 0 || position > countNode - 1) // invalid check
            exit(4);
        else if (position == 0)
            deleteFromFirst();
        else if (position == countNode - 1)
            deleteFromLast();
        else
        {
            Node *temp1 = head;

            for (int i = 0; i < position - 1; i++)
                temp1 = temp1->next;

            Node *temp2 = temp1->next;
            temp1->next = temp2->next;
            delete temp2;
            countNode--;
        }
    }

    void displayList()
    {
        if (!head)
            exit(2); // list is empty
        Node *temp = head;
        while (temp)
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

    l1.insertAtFirst(5); // 5
    l1.insertAtFirst(4); // 4 5
    l1.insertAtFirst(3); // 3 4 5
    l1.insertAtFirst(2); // 2 3 4 5
    l1.insertAtFirst(1); // 1 2 3 4 5

    l1.displayList(); // 1 2 3 4 5

    l1.deleteFromFirst(); // 2 3 4 5

    l1.displayList(); // 2 3 4 5

    l1.deleteFromLast(); // 2 3 4

    l1.displayList(); // 2 3 4

    l1.deleteFromAny(1); // 2 4

    l1.displayList(); // 2 4
    
    l1.deleteFromAny(0); // 4

    l1.displayList(); // 4

    return 0;
}
