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

// Recursive Approach
// Time Complexity: O(N)
// Space Complexity: O(H) where H is the height of the tree
class Solution
{
private:
  void dfs(TreeNode *root, vector<int> &ans)
  {
    if (!root)
      return;

    ans.push_back(root->val); // 1. Root
    dfs(root->left, ans);     // 2. Left
    dfs(root->right, ans);    // 3. Right
  }

public:
  vector<int> preorderTraversal(TreeNode *root)
  {
    vector<int> ans;
    dfs(root, ans);
    return ans;
  }
};

// Iterative Approach
// Time Complexity: O(N)
// Space Complexity: O(H) where H is the height of the tree
class Solution
{
public:
  vector<int> preorderTraversal(TreeNode *root)
  {
    if (!root)
      return {};

    vector<int> ans;
    stack<TreeNode *> st;
    st.push(root);

    while (!st.empty())
    {
      TreeNode *curr = st.top();
      st.pop();

      ans.push_back(curr->val); // Process Root

      // Push right child first so left child is processed next
      if (curr->right)
        st.push(curr->right);
      if (curr->left)
        st.push(curr->left);
    }

    return ans;
  }
};