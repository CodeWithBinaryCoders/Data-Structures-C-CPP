// singly linked list local head implementation using pointer to pointer

#include "stdio.h"
#include "stdlib.h"

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

void insertAtFirst(Node **, int data);
void showList(Node *);

int main()
{
    Node *head = NULL;

    insertAtFirst(&head, 3);
    insertAtFirst(&head, 2);
    insertAtFirst(&head, 1);

    showList(head);
    return 0;
}

void insertAtFirst(Node **ptr, int data)
{
    Node *nw = malloc(sizeof(Node));
    nw->data = data;

    nw->next = *ptr;
    *ptr = nw;
}

void showList(Node *head)
{
    while (NULL != head)
    {
        printf("%d ", head->data);
        head = head->next;
    }

    printf("\n");
}