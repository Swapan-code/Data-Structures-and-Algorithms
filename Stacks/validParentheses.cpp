// https://leetcode.com/problems/valid-parentheses/
#include <bits/stdc++.h>
using namespace std;

bool isValid(string s)
{
  stack<char> st;
  for (auto i : s)
  {
    if (i == '(')
      st.push(')');
    else if (i == '{')
      st.push('}');
    else if (i == '[')
      st.push(']');
    else
    {
      if (st.empty() || i != st.top())
        return false;
      st.pop();
    }
  }

  return st.empty();
}

// Time Complexity: O(N)
// Space Complexity: O(N)