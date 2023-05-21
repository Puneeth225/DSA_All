#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class stackk
{
    int n;
    queue<int> q1;
    queue<int> q2;

public:
    stackk()
    {
        n = 0;
    }
    void pop()
    {
        if (q1.empty())
        {
            return;
        }
        while (q1.size() != 1)
        {
            q2.push(q1.front());
            q1.pop();
        }
        q1.pop();
        n--;
        queue<int> temp = q1;
        q1 = q2;
        q2 = temp;
    }
    void push(int val)
    {
        q1.push(val);
        n++;
    }
    int top()
    {
        if (q1.empty())
        {
            return -1;
        }
        while (q1.size() != 1)
        {
            q2.push(q1.front());
            q1.pop();
        }
        int ans = q1.front();
        q2.push(ans);
        queue<int> temp = q1;
        q1 = q2;
        q2 = temp;
        return ans;
    }
    int size()
    {
        return n;
    }
};
int main()
{
    stackk st;
    st.push(10);
    st.push(12);
    st.push(14);
    st.push(16);
    st.push(18);
    cout << st.top() << "\n";
    st.pop();
    cout << st.top() << "\n";
    cout << st.size() << "\n";
}