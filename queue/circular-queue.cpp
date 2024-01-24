#include <iostream>
#define size 5
using namespace std;

class Queue
{
    int arr[size];
    int front = -1, rear = -1;

public:
    bool isEmpty()
    {
        return (front == -1 && rear == -1);
    }

    bool isFull()
    {
        return (((rear + 1) % size) == front);
    }

    void enqueue(int data)
    {
        if (isFull())
        {
            cout << "Queue overflow!" << endl;
        }
        else if (isEmpty())
            front = rear = 0;
        else
            rear = (rear + 1) % size;

        arr[rear] = data;
    }

    void dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue underflow!" << endl;
        }
        else if (front == rear)
            front = rear = -1;
        else
            front = (front + 1) % size;
    }

    void peek()
    {
        if (isEmpty())
            cout << "Queue empty!" << endl;
        else
            cout << arr[front] << endl;
    }
};

int main()
{
    Queue q;

    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);

    q.dequeue();

    q.enqueue(6);

    q.peek();

    return 0;
}

