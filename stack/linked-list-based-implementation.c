#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

Node *top = NULL;

Node *getNode(int data)
{
    Node *newNode = malloc(sizeof(Node));
    
    if(!newNode) // if malloc() fails
        exit(1);
    
    newNode->data = data;
    newNode->next = NULL;
    
    return newNode;
}

void push(int data)
{
    Node *newNode = getNode(data);

    newNode->next = top;
    top = newNode;
}

void pop() // will not return the popped value
{
    if (!top)
        printf("Stack underflow!\n");
    else
    {
        Node *temp = top;
        top = top->next;
        free(temp);
    }
}

void peek()
{
    if (!top)
        printf("Stack empty!\n");
    else
        printf("%d\n", top->data);
}

int main()
{
    push(3);
    push(2);
    push(1);

    pop();
    
    peek();
    
    return 0;
}