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
  void dfs(TreeNode *root, std::vector<int> &ans)
  {
    if (!root)
      return;

    dfs(root->left, ans);     // 1. Left
    ans.push_back(root->val); // 2. Root
    dfs(root->right, ans);    // 3. Right
  }

public:
  vector<int> inorderTraversal(TreeNode *root)
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
  vector<int> inorderTraversal(TreeNode *root)
  {
    if (!root)
      return {};

    vector<int> ans;
    stack<TreeNode *> st;
    st.push(root);
    TreeNode *curr = root;

    while (!st.empty())
    {
      while (curr && curr->left)
      {
        curr = curr->left;
        st.push(curr);
      }

      curr = st.top();
      ans.push_back(curr->val);
      st.pop();

      if (curr->right)
        st.push(curr->right);
      curr = curr->right;
    }

    return ans;
  }
};