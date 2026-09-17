#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// Time Complexity: O(N)
// Space Complexity: O(W) where W is the maximum width of the tree. In the worst case, W can be N/2 for a perfect binary tree, leading to O(N) space complexity.

class Solution
{
public:
  vector<vector<int>> levelOrder(TreeNode *root)
  {
    vector<vector<int>> ans;
    if (!root)
      return ans;
    queue<TreeNode *> q;
    q.push(root);

    while (!q.empty())
    {
      vector<int> temp;
      int k = q.size();
      for (int i = 1; i <= k; i++)
      {
        TreeNode *node = q.front();
        q.pop();
        temp.push_back(node->val);
        if (node->left)
          q.push(node->left);
        if (node->right)
          q.push(node->right);
      }
      ans.push_back(temp);
    }

    return ans;
  }
};