#define MAX 4 // size of the array

#include <stdio.h>
#include <stdbool.h>
// #define bool _Bool
// #define true 1
// #define false 0

char stack[MAX]; // char array of size 8
int top = -1; // to track the top of the stack

void push(char);
void pop();
void peek();

int main()
{
    push('A'); // top A
    push('B'); // top B
    push('C'); // top C
    push('D'); // top D
    push('E'); // overflow

    peek(); // D

    pop(); // top C

    peek(); // C

    pop(); // B
    pop(); // A

    peek(); // A

    pop(); // underflow

    peek(); // underflow

    return 0;
}

bool overflow() // _Bool overflow() or, int overflow()
{
    if (MAX - 1 == top)
        return true; // return 1

    return false; // return 0;
}

bool underflow()
{
    if (-1 == top)
        return true;
    
    return false;
}

void push(char data)
{
    if (overflow()) // if (true == overflow())
    {
        printf("Stack overflow! Cannot push '%c'.\n", data);
        return;
    }

    top++;
    stack[top] = data;
    // stack[++top] = data;
}

void pop() // will return the popped data
{
    if (underflow())
    {
        printf("Stack underflow! Cannot pop.\n");
        return;
    }

    top--;
}

void peek()
{
    if (underflow())
    {
        printf("Stack underflow! No data to show.\n");
        return;
    }

    printf("%c\n", stack[top]);
}