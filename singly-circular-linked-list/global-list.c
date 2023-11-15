#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

Node *tail = NULL;
int count = 0;

// functions
void insertAtBeginning(int);
void insertAtEnd(int);
void insert(int, int); // data, zero based position
void display();

int main()
{
    insertAtBeginning(2);
    insertAtBeginning(1);
    insertAtEnd(3);
    insertAtEnd(4);
    insert(10, 0);
    insert(20, 5);
    insert(30, 3);

    display();

    return 0;
}

Node *getNode(int data)
{
    Node *newNode = malloc(sizeof(Node));

    newNode->data = data;
    newNode->next = NULL;

    return newNode;
}

void insertAtBeginning(int data)
{
    Node *newNode = getNode(data); // create node

    // if list is empty
    if (NULL == tail) // if (0 == count)
    {
        tail = newNode;
        newNode->next = newNode;
    }
    else
    {
        newNode->next = tail->next;
        tail->next = newNode;
    }

    count++; // increment node counter
}

void insertAtEnd(int data)
{
    Node *newNode = getNode(data); // create node

    // if list is empty
    if (NULL == tail) // if (0 == count)
    {
        tail = newNode;
        newNode->next = newNode;
    }
    else
    {
        newNode->next = tail->next;
        tail->next = newNode;
        tail = newNode; // update tail
    }

    count++; // increment node counter
}

void insert(int data, int position)
{
    if (position < 0 || position > count) // invalid
        exit(2);

    if (0 == position)
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

    Node *newNode = getNode(data);

    newNode->next = temp->next;
    temp->next = newNode;

    count++;
}

void display()
{
    if (NULL == tail) // empty list
    {
        printf("No data\n");
        return;
    }

    Node *temp = tail->next;

    do
    {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != tail->next);

    printf("\n");
}