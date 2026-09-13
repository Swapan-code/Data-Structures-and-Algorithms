#include <bits/stdc++.h>
using namespace std;

// Using pure Recursion
// Time Complexity: O(N^2)
// Space Complexity: O(N)

class Solution
{
public:
  void insertAtBottom(stack<int> &st, int val)
  {
    if (st.empty())
    {
      st.push(val);
      return;
    }

    int temp = st.top();
    st.pop();
    insertAtBottom(st, val);
    st.push(temp);
  }

  void reverseStack(stack<int> &st)
  {
    if (st.empty() || st.size() == 1)
      return;

    int temp = st.top();
    st.pop();
    reverseStack(st);
    insertAtBottom(st, temp);
  }
};