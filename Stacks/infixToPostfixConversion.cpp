// https://www.geeksforgeeks.org/problems/infix-to-postfix-1587115620/1

#include <bits/stdc++.h>
using namespace std;

// Approach 1: Dijkstra's Shunting-Yard Algorithm
// Time Complexity: O(N)
// Space Complexity: O(N)
class Solution
{
public:
  int precedence(char ch)
  {
    if (ch == '^')
      return 3;
    if (ch == '*' || ch == '/')
      return 2;
    if (ch == '+' || ch == '-')
      return 1;
    return -1;
  }

  bool isRightAssociative(char ch)
  {
    return ch == '^';
  }

  string infixToPostfix(string &s)
  {
    stack<char> st;
    string res = "";
    for (auto i : s)
    {
      if ((i >= 'a' && i <= 'z') || (i >= 'A' && i <= 'Z') || (i >= '0' && i <= '9'))
      {
        res += i;
      }
      else if (i == '(')
      {
        st.push(i);
      }
      else if (i == ')')
      {
        while (!st.empty() && st.top() != '(')
        {
          res += st.top();
          st.pop();
        }
        if (!st.empty())
          st.pop();
      }
      else
      {
        while ((!st.empty()) && ((precedence(st.top()) > precedence(i)) || ((precedence(st.top()) == precedence(i)) && !isRightAssociative(i))))
        {
          res += st.top();
          st.pop();
        }
        st.push(i);
      }
    }

    // Empty stack at the end
    while (!st.empty())
    {
      res += st.top();
      st.pop();
    }
    return res;
  }
};
