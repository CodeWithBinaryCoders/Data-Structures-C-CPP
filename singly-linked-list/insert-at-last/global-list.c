// LINKED LIST
// INSERT AT LAST IN CONSTANT TIME

#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

Node *head = NULL;
Node *tail = NULL;

void insertAtLast(int data);
void displayList();

int main()
{
    insertAtLast(1);
    insertAtLast(2);
    insertAtLast(3);

    displayList();

    return 0;
}

void insertAtLast(int data)
{
    // node creation
    Node *nw = malloc(sizeof(Node));
    nw->data = data;
    nw->next = NULL;

    // if list is empty
    if (NULL == head)
    {
        head = nw;
        tail = nw;
    }
    // if element is present
    else
    {
        tail->next = nw;
        tail = nw; // tail = tail->next;
    }
}

void displayList()
{
    Node *temp = head;

    while (NULL != temp)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    printf("\n");
}