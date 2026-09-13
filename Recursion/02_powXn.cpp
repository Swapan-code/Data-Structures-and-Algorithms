// https://leetcode.com/problems/powx-n/description/

#include <bits/stdc++.h>
using namespace std;

// Using Recursion
// Time Complexity: O(log N)
// Space Complexity: O(log N)
double helper(double x, long long N)
{
  if (N == 0)
    return 1;
  return N & 1 ? x * helper(x * x, N / 2) : helper(x * x, N / 2);
}

double myPow(double x, int n)
{
  if (x == 0)
    return 0;
  long long N = n;
  if (N < 0)
  {
    N = -1 * N;
    x = 1 / x;
  }

  return helper(x, N);
}

// Iterative Approach
// Time Complexity: O(log N)
// Space Complexity: O(1)

double myPow(double x, int n)
{
  if (x == 0)
    return 0;
  long long N = n;
  if (N < 0)
  {
    x = 1 / x;
    N = -1 * N;
  }

  double ans = 1;
  while (N)
  {
    if (N & 1)
      ans *= x;
    x *= x;
    N >>= 1;
  }

  return ans;
}