#include <stdio.h>
#include <stdbool.h>
#define MAX 8 // macro definition of size

char queue[MAX]; // global array for queue
int front = 0; // empty queue
int rear = 0; // empty queue

void enqueue(char); // int data
void dequeue();
void peek(); // show front

int main()
{
    peek(); // empty
    dequeue(); // empty

    enqueue('A'); // A
    enqueue('B'); // A B
    enqueue('C'); // A B C
    enqueue('D'); // A B C D
    enqueue('E'); // A B C D E

    peek(); // A

    dequeue(); // B C D E
    dequeue(); // C D E

    peek(); // C

    enqueue('F'); // C D E F
    enqueue('G'); // C D E F G

    peek(); // C

    dequeue(); // D E F G
    dequeue(); // E F G
    dequeue(); //F G
    dequeue(); // G

    peek(); // G

    dequeue(); // empty

    peek(); // empty

    return 0;
}

bool isEmpty()
{
    if (front == rear)
        return true; // empty
    // else
    return false; // not empty
}

bool isFull()
{
    if (MAX == rear)
        return true; // full
    // else
    return false; // not full
}

void enqueue(char data)
{
    if (isFull()) // if (true == isFull())
    {
        printf("\nQueue is full! Cannot enqueue element!\n");
        return;
    }
    // else
    queue[rear] = data;
    rear++;
}

void dequeue()
{
    if (isEmpty())
    {
        printf("\nQueue is empty! Cannot dequeue element!\n");
        return;
    }
    // else
    front++;
}

void peek()
{
    if (isEmpty())
    {
        printf("\nQueue is empty! Cannot show element!\n");
        return;
    }
    // else
    printf("\n%c\n", queue[front]);
}