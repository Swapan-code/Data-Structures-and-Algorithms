//  https://leetcode.com/problems/minimum-remove-to-make-valid-parentheses/

#include <bits/stdc++.h>
using namespace std;

// Approach 1: My first try code (using queue)
// Time Complexity: O(N)
// Space Complexity: O(N)
string minRemoveToMakeValid(string s)
{
  queue<int> q;
  string res = "";

  for (int i = 0; i < s.size(); i++)
  {
    if (s[i] == '(')
    {
      q.push(res.size());
      res += s[i];
    }
    else if (s[i] == ')')
    {
      if (!q.empty())
      {
        res += s[i];
        q.pop();
      }
    }
    else
      res += s[i];
  }

  if (q.empty())
    return res;

  // remove ('s
  int start = q.front(), idx = start;
  for (int i = start; i < res.size(); i++)
  {
    if (res[i] != '(')
    {
      res[idx++] = res[i];
    }
  }
  res.resize(idx);
  return res;
}

// Approach 2: Stack with Index Tracking
// Time Complexity: O(N)
// Space Complexity: O(N)
string minRemoveToMakeValid(string s)
{
  int n = s.size();
  stack<int> st;
  for (int i = 0; i < n; i++)
  {
    if (s[i] == '(')
      st.push(i);
    else if (s[i] == ')')
    {
      if (st.empty())
        s[i] = '*';
      else
        st.pop();
    }
  }

  while (!st.empty())
  {
    s[st.top()] = '*';
    st.pop();
  }

  // Remove *'s
  string res = "";
  for (auto i : s)
  {
    if (i != '*')
      res += i;
  }
  return res;
}

// Approach 3: Two-Pass Counter (left to right, then right to left)
// Time Complexity: O(N)
// Space Complexity: O(1)
string minRemoveToMakeValid(string s)
{
  int n = s.size();

  // First pass: Left to Right
  int c = 0, idx = 0;
  for (int i = 0; i < s.size(); i++)
  {
    if (s[i] == '(')
    {
      c++;
      s[idx++] = s[i];
    }
    else if (s[i] == ')')
    {
      if (c != 0)
      {
        c--;
        s[idx++] = s[i];
      }
    }
    else
    {
      s[idx++] = s[i];
    }
  }
  s.resize(idx);

  // Second pass: Right to Left
  c = 0, n = s.size(), idx = n - 1;
  for (int i = n - 1; i >= 0; i--)
  {
    if (s[i] == '(')
    {
      if (c != 0)
      {
        c--;
        s[idx--] = s[i];
      }
    }
    else if (s[i] == ')')
    {
      c++;
      s[idx--] = s[i];
    }
    else
    {
      s[idx--] = s[i];
    }
  }

  for (int i = idx + 1; i < n; i++)
  {
    s[i - idx - 1] = s[i];
  }
  s.resize(n - idx - 1);
  return s;
}