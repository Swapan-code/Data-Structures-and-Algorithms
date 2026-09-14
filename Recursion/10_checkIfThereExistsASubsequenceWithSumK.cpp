#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
  bool helper(vector<int> &arr, int target, int i)
  {
    // Base Case 1: Target reached
    if (target == 0)
      return true;

    // Base Case 2: Out of bounds or target exceeded
    if (i == arr.size() || target < 0)
      return false;

    // Choice 1: Exclude arr[i]
    // Choice 2: Include arr[i] (short-circuits using ||)
    return helper(arr, target, i + 1) || helper(arr, target - arr[i], i + 1);
  }

public:
  bool isSubsetSum(vector<int> &arr, int target)
  {
    return helper(arr, target, 0);
  }
};