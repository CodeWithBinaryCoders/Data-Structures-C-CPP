#include <iostream>
#include <stack>
using namespace std;
int main()
{
    stack<int> s;

    s.push(1); // top = 1
    s.push(4); // top = 4
    s.push(3); // top = 3

    cout << s.top() << endl; // 3

    s.pop(); // top = 4

    cout << s.top() << endl; // 4

    cout << s.empty() << endl; // 0

    while (!s.empty())
        s.pop();

    cout << s.empty() << endl; // 1

    return 0;
}