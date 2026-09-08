// https://leetcode.com/problems/minimum-add-to-make-parentheses-valid/

#include <bits/stdc++.h>
using namespace std;

// Approach 1: Using Explicit Stack
// Time Complexity: O(N)
// Space Complexity: O(N)
int minAddToMakeValid(string s)
{
  int count = 0;
  stack<char> st;
  for (auto i : s)
  {
    if (i == '(')
      st.push(i);
    else
    {
      if (st.empty())
        count++;
      else
        st.pop();
    }
  }

  count += st.size();
  return count;
}

// Approach 2: Using Counter Variable
// Time Complexity: O(N)
// Space Complexity: O(1)
int minAddToMakeValid(string s)
{
  int c = 0, ans = 0;
  for (auto i : s)
  {
    if (i == '(')
      c++;
    else
    {
      if (c == 0)
        ans++;
      else
        c--;
    }
  }

  ans += c;
  return ans;
}