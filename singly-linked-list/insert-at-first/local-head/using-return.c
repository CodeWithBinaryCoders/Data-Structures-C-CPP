// singly linked list local head implementation using return

#include "stdio.h"
#include "stdlib.h"

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

Node *insertAtFirst(Node *, int data);
void showList(Node *);

int main()
{
    Node *head = NULL;

    head = insertAtFirst(head, 3); // 3
    head = insertAtFirst(head, 2); // 2 3
    head = insertAtFirst(head, 1); // 1 2 3

    showList(head);
    return 0;
}

Node *insertAtFirst(Node *head, int data)
{
    Node *nw = malloc(sizeof(Node));
    nw->data = data;

    nw->next = head;
    head = nw;

    return head;
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