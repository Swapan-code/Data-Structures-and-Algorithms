// https://leetcode.com/problems/generate-binary-strings-without-adjacent-zeros/description/

#include <bits/stdc++.h>
using namespace std;

// Using pure Recursion
// Time Complexity: O(N * 2^N)
// Space Complexity: O(N)

class Solution
{
public:
  void helper(string &s, int n, vector<string> &ans)
  {
    if (s.size() == n)
    {
      ans.push_back(s);
      return;
    }

    // '1' can always be appended
    s.push_back('1');
    helper(s, n, ans);
    s.pop_back();

    // '0' can only be appended if previous char is '1'
    if (s.back() == '1')
    {
      s.push_back('0');
      helper(s, n, ans);
      s.pop_back();
    }
  }

  vector<string> validStrings(int n)
  {
    vector<string> ans;
    string s = "";

    s.push_back('0');
    helper(s, n, ans);
    s.pop_back();

    s.push_back('1');
    helper(s, n, ans);
    s.pop_back();

    return ans;
  }
};