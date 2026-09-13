#include <bits/stdc++.h>
using namespace std;

// Using pure Recursion
// Time Complexity: O(N^2)
// Space Complexity: O(N)

class Solution
{
public:
  void insertAtCorrectPos(stack<int> &st, int val)
  {
    if (st.empty() || val >= st.top())
    {
      st.push(val);
      return;
    }

    int temp = st.top();
    st.pop();
    insertAtCorrectPos(st, val);
    st.push(temp);
  }

  void sortStack(stack<int> &st)
  {
    if (st.size() <= 1)
      return;

    int temp = st.top();
    st.pop();
    sortStack(st);
    insertAtCorrectPos(st, temp);
  }
};