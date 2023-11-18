#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

Node *getNode(int data)
{
    Node *newNode = malloc(sizeof (Node));

    newNode->data = data;
    newNode->next = NULL;

    return newNode;
}

Node *tail = NULL;
int count = 0;

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

void insertAtPosition(int data, int position)
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

void deleteFromFirst()
{
    if (!tail) // if (tail == NULL)
        exit(3);

    else if (tail->next == tail) // only single node is present
    {
        free(tail);
        tail = NULL;
    }
    else
    {
        Node *temp = tail->next;
        tail->next = temp->next;
        free(temp);
    }
    count--;
}

void deleteFromEnd()
{
    if (!tail) // list is empty
        exit(4);

    else if (tail->next == tail) // only single node is present
    {
        free(tail);
        tail = NULL;
    }

    else
    {
        Node *temp = tail;
        while (tail->next != temp)
            tail = tail->next;
        tail->next = temp->next;
        free(temp);
    }
    count--;
}

void deleteFromPosition(int position)
{
    if (!tail) // list is empty
        exit(5);

    else if (position < 0 || position > count - 1)
        exit(5);

    else if (position == 0)
        deleteFromFirst();
    else if (position == count - 1)
        deleteFromEnd();

    else
    {
        Node *temp = tail->next;

        for (int i = 0; i < position - 1; i++)
            temp = temp->next;

        Node *remove = temp->next;
        temp->next = remove->next;

        free(remove);
        count--;
    }
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

int main()
{
    insertAtEnd(1); // 1
    insertAtEnd(2); // 1 2
    insertAtEnd(3); // 1 2 3
    insertAtEnd(4); // 1 2 3 4
    insertAtEnd(5); // 1 2 3 4 5
    insertAtEnd(6); // 1 2 3 4 5 6
    insertAtEnd(7);  // 1 2 3 4 5 6 7

    deleteFromFirst(); // 2 3 4 5 6 7

    deleteFromEnd(); // 2 3 4 5 6

    deleteFromPosition(2); // 2 3 5 6

    deleteFromFirst(); // 3 5 6

    deleteFromEnd(); // 3 5


    display(); // 3 5

    return 0;
}