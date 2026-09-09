// https://www.geeksforgeeks.org/problems/postfix-to-infix-conversion/1

#include <bits/stdc++.h>
using namespace std;

// Approach 1: Using Operand Stack
// Time Complexity: O(N)
// Space Complexity: O(N)

string postToInfix(string &s)
{
  stack<string> st;
  for (auto i : s)
  {
    if (i == '+' || i == '-' || i == '*' || i == '/' || i == '^' || i == '%')
    {
      string temp = "";
      string op2 = st.top();
      st.pop();
      string op1 = st.top();
      st.pop();
      temp += '(' + op1 + i + op2 + ')';
      st.push(temp);
    }
    else
    {
      st.push(string(1, i));
    }
  }

  return st.top();
}