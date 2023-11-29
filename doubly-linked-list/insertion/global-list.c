#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *prev, *next;
} Node;

Node *head = NULL, *tail = NULL;
int countNode = 0;

Node *getNode(int data)
{
    Node *newNode = malloc(sizeof (Node));

    if (!newNode) // if (newNode == NULL)
        exit(1);

    newNode->data = data;
    newNode->prev = newNode->next = NULL;

    return newNode;
}

void insertAtFirst(int data)
{
    Node *newNode = getNode(data);

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
    Node *newNode = getNode(data);

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
        Node *newNode = getNode(data);

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
        printf("Empty list!\n");
        return;
    }

    else
    {
        while (temp) // while (temp != NULL)
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

void reverseDisplay()
{
    Node *temp = tail;

    if (!head && !tail)
    {
        printf("Empty list!\n");
        return;
    }

    else
    {
        while (temp) // while (temp != NULL)
        {
            printf("%d ", temp->data);
            temp = temp->prev;
        }
        printf("\n");
    }
}

int main()
{
    insertAtLast(2); // 2
    insertAtLast(3); // 2 3
    insertAtLast(4); // 2 3 4
    insertAtLast(5); // 2 3 4 5

    insertAtFirst(1); // 1 2 3 4 5

    forwardDisplay(); // 1 2 3 4 5
    reverseDisplay(); // 5 4 3 2 1
    
    insertAtPosition(0, 0); // 0 1 2 3 4 5

    forwardDisplay(); // 0 1 2 3 4 5

    insertAtPosition(6, 6); // 0 1 2 3 4 5 6

    forwardDisplay(); // 0 1 2 3 4 5 6
    
    insertAtPosition(4, 404); // 0 1 2 3 404 4 5 6

    forwardDisplay(); // 0 1 2 3 404 4 5 6
    reverseDisplay(); // 6 5 4 404 3 2 1 0

    return 0;
}