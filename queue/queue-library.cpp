#include <iostream>
#include <queue>
using namespace std;

int main()
{
    queue<int> q;

    q.push(1); // 1
    q.push(2); // 1 2
    q.push(3); // 1 2 3
    q.push(4); // 1 2 3 4
    q.push(5); // 1 2 3 4 5

    q.pop(); // 2 3 4 5
    q.pop(); // 3 4 5

    cout << q.front() << endl; // 3

    cout << q.empty() << endl; // false

    while (!q.empty())
        q.pop();

    cout << q.empty() << endl; // true

    return 0;
}

