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
void display();
void reversePrint(Node *);

int main(void)
{
    insertAtBeginning(30); // 30
    insertAtBeginning(20); // 20 30
    insertAtBeginning(10); // 10 20 30

    display(); // 10 20 30
    reversePrint(head); // 30 20 10

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

void reversePrint(Node *pointer)
{
    if (!pointer) // if (NULL == pointer)
        return;

    reversePrint(pointer->next);
    printf("%d ", pointer->data);
}