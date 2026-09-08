// https://www.geeksforgeeks.org/problems/reverse-a-stack/1

#include <bits/stdc++.h>
using namespace std;

// Approach 1: Pure Recursion (In-place)
// Time Complexity: O(N^2)
// Space Complexity: O(N)
void insertAtBottom(stack<int> &st, int ele)
{
  if (st.empty())
  {
    st.push(ele);
    return;
  }

  int temp = st.top();
  st.pop();
  insertAtBottom(st, ele);
  st.push(temp);
}

void reverseStack(stack<int> &st)
{
  if (st.size() == 1)
    return;
  int ele = st.top();
  st.pop();
  reverseStack(st);
  insertAtBottom(st, ele);
}

// Approach 2: Using Auxiliary Stack or another Data Structure
// Time Complexity: O(N)
// Space Complexity: O(N)
void reverseStack(stack<int> &st)
{
  stack<int> temp;
  while (!st.empty())
  {
    temp.push(st.top());
    st.pop();
  }

  st = temp;
}
