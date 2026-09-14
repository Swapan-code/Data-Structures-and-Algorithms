// https:// leetcode.com/problems/subsets/description/

#include <bits/stdc++.h>
using namespace std;

// Backtracking
// Time Complexity: O(N * 2^N)
// Space Complexity: O(N)

class Solution
{
private:
  void helper(vector<int> &nums, vector<vector<int>> &ans, int i, vector<int> &temp)
  {
    if (i == nums.size())
    {
      ans.push_back(temp);
      return;
    }

    // Take index i
    temp.push_back(nums[i]);
    helper(nums, ans, i + 1, temp);
    temp.pop_back();

    // Don't take index i
    helper(nums, ans, i + 1, temp);
  }

public:
  vector<vector<int>> subsets(vector<int> &nums)
  {
    vector<vector<int>> ans;
    vector<int> temp;
    helper(nums, ans, 0, temp);
    return ans;
  }
};