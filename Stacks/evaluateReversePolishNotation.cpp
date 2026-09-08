//  https://leetcode.com/problems/evaluate-reverse-polish-notation/description/

#include <bits/stdc++.h>
using namespace std;

// Approach 1: Using Stack
// Time Complexity: O(N)
// Space Complexity: O(N)
int evalRPN(vector<string> &tokens)
{
  stack<int> st;
  for (auto i : tokens)
  {
    if (i == "+" || i == "-" || i == "*" || i == "/")
    {
      int op2 = st.top();
      st.pop();
      int op1 = st.top();
      st.pop();

      if (i == "+")
        st.push(op1 + op2);
      else if (i == "-")
        st.push(op1 - op2);
      else if (i == "*")
        st.push(op1 * op2);
      else if (i == "/")
        st.push(op1 / op2);
    }
    else
    {
      st.push(stoi(i));
    }
  }
  return st.top();
}

// Approach 2: Simulating Stack
// Time Complexity: O(N)
// Space Complexity: O(1)
int evalRPN(vector<string> &tokens)
{
  int top = 0;
  for (int i = 0; i < tokens.size(); i++)
  {
    string s = tokens[i];
    if (s == "+" || s == "-" || s == "*" || s == "/")
    {
      int op2 = stoi(tokens[--top]);
      int op1 = stoi(tokens[--top]);
      if (s == "+")
        tokens[top++] = to_string(op1 + op2);
      else if (s == "-")
        tokens[top++] = to_string(op1 - op2);
      else if (s == "*")
        tokens[top++] = to_string(op1 * op2);
      else if (s == "/")
        tokens[top++] = to_string(op1 / op2);
    }
    else
    {
      tokens[top++] = s;
    }
  }

  return stoi(tokens[0]);
}