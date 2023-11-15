// Linked List with global head and tail (All the insertion & deletion functions)

#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

Node *head = NULL, *tail = NULL;

int countNode = 0;

Node *getNode(int data)
{
    Node *newNode = malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertAtFirst(int data)
{
    Node *newNode = getNode(data);
    if (!countNode) // if (countNode == 0)
        head = tail = newNode;
    else
    {
        newNode->next = head;
        head = newNode;
    }
    countNode++;
}

void insertAtLast(int data)
{
    Node *newNode = getNode(data);
    if (!countNode) // if (countNode == 0)
        head = tail = newNode;
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
        Node *newNode = getNode(data);
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
    free(temp);

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
        free(head);
        head = tail = NULL;
    }
    else
    {
        Node *temp = head;

        while (temp->next != tail)
            temp = temp->next;

        temp->next = NULL;
        free(tail);
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
        free(temp2);
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
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    insertAtFirst(5);
    insertAtFirst(4);
    insertAtFirst(3);
    insertAtFirst(2);
    insertAtFirst(1);

    deleteFromFirst();
    deleteFromLast();
    deleteFromAny(1);
    deleteFromAny(0);

    displayList();

    return 0;
}