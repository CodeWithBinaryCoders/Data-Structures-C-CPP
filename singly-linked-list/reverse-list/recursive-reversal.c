// singly linked list global head implementation
// reversal of singly linked list

#include <stdio.h>
#include <stdlib.h>

typedef struct Node // structure definition
{
    int data;
    struct Node *next;
} Node;

Node *head = NULL; // declaring the head pointer

void insertAtBeginning(int);
void reverseList(Node *);
void display();

int main(void)
{
    insertAtBeginning(30); // 30
    insertAtBeginning(20); // 20 30
    insertAtBeginning(10); // 10 20 30

    printf("Original list:\n");
    display(); // 10 20 30

    reverseList(head); // 30 20 10

    printf("\nReversed list:\n");
    display(); // 30 20 10

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

void reverseList(Node *pointer)
{
    if (!pointer->next) // if (NULL == pointer->next)
    {
        head = pointer;
        return;
    }

    reverseList(pointer->next);

    Node *temp = pointer->next;
    temp->next = pointer;
    pointer->next = NULL;
}

void display()
{
    Node *temp = head;

    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    printf("\n");
}