#include<iostream>
#include<queue>
using namespace std;
int main()
{
    priority_queue<int, vector<int>, greater<int> > s ; // For lower priority //
    s.push(20);
    s.push(15);
    s.push(12);
    s.push(10);
    s.push(30);
    s.push(16);
    while(!s.empty())
    {
        cout<<s.top()<<" ";
        s.pop();
    }
    return 0;
}
