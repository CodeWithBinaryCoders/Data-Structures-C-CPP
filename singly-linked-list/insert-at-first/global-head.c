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

int main(void)
{
    insertAtBeginning(30);
    insertAtBeginning(20);
    insertAtBeginning(10);

    display();

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