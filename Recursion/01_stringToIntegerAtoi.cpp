// https://leetcode.com/problems/string-to-integer-atoi/description/

#include <bits/stdc++.h>
using namespace std;

// Using Recursion
// Time Complexity: O(N)
// Space Complexity: O(N)
class Solution
{
public:
  int helper(string s, int i, long long ans, int sign)
  {
    if (i >= s.size() || s[i] < '0' || s[i] > '9')
    {
      return sign * ans;
    }

    ans = ans * 10 + s[i] - '0';
    if (sign == 1 && ans >= INT_MAX)
      return INT_MAX;
    if (sign == -1 && -1 * ans <= INT_MIN)
      return INT_MIN;

    return helper(s, i + 1, ans, sign);
  }

  int myAtoi(string s)
  {
    int sign = 1;
    int i = 0, n = s.size();

    // Whitespaces ignore
    while (i < n && s[i] == ' ')
      i++;
    if (i == n)
      return 0;

    // Signedness
    if (s[i] == '-')
    {
      sign = -1;
      i++;
    }
    else if (s[i] == '+')
      i++;

    return helper(s, i, 0, sign);
  }
};

// Iterative Approach
// Time Complexity: O(N)
// Space Complexity: O(1)
class Solution
{
public:
  int myAtoi(string s)
  {
    int ans = 0;
    bool neg = 0;
    int i = 0, n = s.size();

    // Whitespaces ignore
    while (i < n && s[i] == ' ')
      i++;
    if (i == n)
      return 0;

    // Signedness
    if (s[i] == '-')
    {
      neg = 1;
      i++;
    }
    else if (s[i] == '+')
      i++;

    // Skip leading zeroes
    while (i < n && s[i] == '0')
      i++;

    while (i < n && s[i] >= '0' && s[i] <= '9')
    {
      if ((ans > INT_MAX / 10) || (ans == INT_MAX / 10 && s[i] >= '7'))
        return INT_MAX;
      else if ((ans < INT_MIN / 10) || (ans == INT_MIN / 10 && s[i] >= '8'))
        return INT_MIN;

      ans = (neg) ? ans * 10 - (s[i] - '0') : ans * 10 + (s[i] - '0');
      i++;
    }

    return ans;
  }
};