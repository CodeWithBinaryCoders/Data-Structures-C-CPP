#include <iostream>
#include <stack>
using namespace std;

bool checkValidPair(char opening, char closing)
{
    if ((opening == '(' && closing == ')') || (opening == '{' && closing == '}') || (opening == '[' && closing == ']'))
        return true;
    return false;
}

bool checkBalancedBrackets(string expression)
{
    stack<char> s;

    for (char ch : expression)
        if (ch == '(' || ch == '{' || ch == '[')
            s.push(ch);
        else if (ch == ')' || ch == '}' || ch == ']')
        {
            if (s.empty() || !checkValidPair(s.top(), ch))
                return false;
            else
                s.pop();
        }

    return s.empty() ? true : false;
}

int main()
{
    string expression;
    getline(cin, expression);

    if (checkBalancedBrackets(expression))
        cout << "Balanced" << endl;
    else
        cout << "Not balanced" << endl;

    return 0;
}