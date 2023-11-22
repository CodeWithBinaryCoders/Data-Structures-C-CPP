// singly linked list global head implementation

#include <stdio.h>
#include <stdlib.h>

typedef struct Node // structure definition
{
    int data;
    struct Node *next;
} Node;

Node *head = NULL; // declaring the head pointer

void insertAtBeginning(int);
void recursivePrint(Node *);

int main(void)
{
    insertAtBeginning(30); // 30
    insertAtBeginning(20); // 20 30
    insertAtBeginning(10); // 10 20 30

    recursivePrint(head); // 10 20 30

    printf("\n");

    return 0;
}

void insertAtBeginning(int data)
{
    Node *temp = malloc(sizeof (Node));
    temp->data = data;

    // insert at beginning
    temp->next = head;
    head = temp;
}

void recursivePrint(Node *pointer)
{
    if (!pointer) // if (NULL == pointer)
        return;

    printf("%d ", pointer->data);
    recursivePrint(pointer->next);
}
