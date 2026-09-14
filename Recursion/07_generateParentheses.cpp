// https://leetcode.com/problems/generate-parentheses/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  void helper(string &s, vector<string> &ans, int open, int close, int n)
  {
    if (s.size() == 2 * n)
    {
      ans.push_back(s);
      return;
    }

    // opening condition
    if (open < n)
    {
      s.push_back('(');
      helper(s, ans, open + 1, close, n);
      s.pop_back();
    }

    // closing condition
    if (close < open)
    {
      s.push_back(')');
      helper(s, ans, open, close + 1, n);
      s.pop_back();
    }
  }

  vector<string> generateParenthesis(int n)
  {
    vector<string> ans;
    string s = "";

    helper(s, ans, 0, 0, n);
    return ans;
  }
};