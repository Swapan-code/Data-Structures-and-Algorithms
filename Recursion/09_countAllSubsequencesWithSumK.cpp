#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
  int count(vector<int> &arr, int target, int i)
  {
    if (i == arr.size())
    {
      return target == 0;
    }
    if (target < 0)
      return 0;

    return count(arr, target, i + 1) + count(arr, target - arr[i], i + 1);
  }

public:
  int perfectSum(vector<int> &arr, int target)
  {
    return count(arr, target, 0);
  }
};
