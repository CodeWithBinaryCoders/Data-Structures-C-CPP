#include <iostream>
#include <stack>
using namespace std;

int performOperation(int operand1, int operand2, char operation)
{
    switch (operation)
    {
    case '+':
        return operand1 + operand2;
    case '-':
        return operand1 - operand2;
    case '*':
        return operand1 * operand2;
    case '/':
        return operand1 / operand2;
    }
}

bool isvalidOperator(char ch)
{
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/') ? true : false;
}

bool isValidNumber(char ch)
{
    return (ch >= '0' && ch <= '9') ? true : false;
}

int evaluatePostfix(string expression)
{
    stack<int> s;

    for (int i = 0; i < expression.length(); i++)
    {
        if (expression[i] == ' ' || expression[i] == ',')
            continue;
        else if (isValidNumber(expression[i]))
        {
            int operand = 0;

            while (i < expression.length() && isValidNumber(expression[i]))
            {
                operand = (operand * 10) + (expression[i] - '0');
                i++;
            }
            i--;
            s.push(operand);
        }
        else if (isvalidOperator(expression[i]))
        {
            int operand2 = s.top();
            s.pop();

            int operand1 = s.top();
            s.pop();

            s.push(performOperation(operand1, operand2, expression[i]));
        }
    }
    return s.top();
}

// driver code
int main()
{
    string expression;
    getline(cin, expression);
    cout << evaluatePostfix(expression) << endl;

    return 0;
}