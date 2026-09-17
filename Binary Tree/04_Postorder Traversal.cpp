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
    dfs(root->right, ans);    // 2. Right
    ans.push_back(root->val); // 3. Root
  }

public:
  vector<int> postorderTraversal(TreeNode *root)
  {
    vector<int> ans;
    dfs(root, ans);
    return ans;
  }
};

// Iterative Approach using 2 stacks
// Time Complexity: O(N)
// Space Complexity: O(N) (stores all nodes in stack)
class Solution
{
public:
  vector<int> postorderTraversal(TreeNode *root)
  {
    if (!root)
      return {};

    vector<int> ans;
    stack<TreeNode *> st, post;
    st.push(root);

    while (!st.empty())
    {
      TreeNode *curr = st.top();
      st.pop();
      post.push(curr); // Store node in output order stack

      if (curr->left)
        st.push(curr->left);
      if (curr->right)
        st.push(curr->right);
    }

    while (!post.empty())
    {
      ans.push_back(post.top()->val);
      post.pop();
    }

    return ans;
  }
};

// Iterative Approach using 1 stack
// Time Complexity: O(N)
// Space Complexity: O(H) where H is the height of the tree
class Solution
{
public:
  vector<int> postorderTraversal(TreeNode *root)
  {
    if (!root)
      return {};
    vector<int> ans;
    stack<TreeNode *> st;
    TreeNode *curr = root;
    TreeNode *lastVisited = NULL;

    while (curr || !st.empty())
    {
      if (curr)
      {
        st.push(curr);
        curr = curr->left; // Go deep left
      }
      else
      {
        TreeNode *peekNode = st.top();
        // If right child exists and traversing from left child, move right
        if (peekNode->right && lastVisited != peekNode->right)
        {
          curr = peekNode->right;
        }
        else
        {
          ans.push_back(peekNode->val);
          lastVisited = peekNode;
          st.pop();
        }
      }
    }

    return ans;
  }
};