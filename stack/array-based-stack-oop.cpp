#include <iostream>
using namespace std;

#define maxSize 5

class Stack
{
    int arr[maxSize];
    int top = -1;

    bool isFull()
    {
        if (top == maxSize - 1)
            return true;
        return false;
    }

    bool isEmpty()
    {
        if (top == -1)
            return true;
        return false;
    }

public:
    void push(int data)
    {
        if (isFull())
            cout << "Stack overflow!" << endl;
        else
            arr[++top] = data;
    }

    void pop() // will not return the popped value
    {
        if (isEmpty())
            cout << "Stack underflow!" << endl;
        else
            top--;
    }

    void peek()
    {
        if (isEmpty())
            cout << "Stack empty!" << endl;
        else
            cout << arr[top] << endl;
    }

    bool checkEmpty()
    {
        if (isEmpty())
            cout << '1' << endl;
        else
            cout << '0' << endl;
    }

    void clearStack()
    {
        top = -1;
    }
};

int main()
{
    Stack s;

    s.push(1);
    s.push(2);
    s.push(3);

    s.pop();

    s.peek();

    s.checkEmpty();

    s.clearStack();

    s.checkEmpty();

    return 0;
}