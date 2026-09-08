// https://leetcode.com/problems/remove-outermost-parentheses/description/

#include <bits/stdc++.h>
using namespace std;

// Approach 1: Using Stack
// Time Complexity: O(N)
// Space Complexity: O(N)
string removeOuterParentheses(string s)
{
  string res = "";
  stack<char> st;
  for (auto i : s)
  {
    if (i == '(')
    {
      st.push(i);
      if (st.size() > 1)
        res += i;
    }
    else
    {
      st.pop();
      if (st.size() > 0)
        res += i;
    }
  }

  return res;
}

// Approach 2: Using Count Variable
// Time Complexity: O(N)
// Space Complexity: O(1)
string removeOuterParentheses(string s)
{
  string res = "";
  int c = 0;
  for (auto i : s)
  {
    if (i == '(')
    {
      c++;
      if (c > 1)
        res += i;
    }
    else
    {
      c--;
      if (c > 0)
        res += i;
    }
  }

  return res;
}