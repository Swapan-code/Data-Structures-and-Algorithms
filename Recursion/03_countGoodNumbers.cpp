// https://leetcode.com/problems/count-good-numbers/description/

#include <bits/stdc++.h>
using namespace std;

// Using modular binary exponentiation
// Time Complexity: O(log N)
// Space Complexity: O(1)

class Solution
{
public:
  long long mod = 1e9 + 7;

  int myPow(long long x, long long n)
  {
    long long ans = 1;
    while (n)
    {
      if (n & 1)
        ans = (ans * x) % mod;
      x = (x * x) % mod;
      n >>= 1;
    }

    return ans;
  }

  int countGoodNumbers(long long n)
  {
    long long ans = myPow(20, n / 2);
    return n & 1 ? (5 * ans) % mod : ans;
  }
};