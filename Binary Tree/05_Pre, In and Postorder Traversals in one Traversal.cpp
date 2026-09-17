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

class Solution
{
public:
  struct AllTraversals
  {
    vector<int> preorder;
    vector<int> inorder;
    vector<int> postorder;
  };

  AllTraversals getTreeTraversals(TreeNode *root)
  {
    AllTraversals result;
    if (!root)
      return result;

    // Stack stores pair: {TreeNode pointer, visit state (1, 2, or 3)}
    stack<pair<TreeNode *, int>> st;
    st.push({root, 1});

    while (!st.empty())
    {
      auto &[node, state] = st.top();

      if (state == 1)
      {
        // 1. Preorder: Record value on 1st visit
        result.preorder.push_back(node->val);
        state = 2; // Advance state

        if (node->left)
          st.push({node->left, 1});
      }
      else if (state == 2)
      {
        // 2. Inorder: Record value on 2nd visit
        result.inorder.push_back(node->val);
        state = 3; // Advance state

        if (node->right)
          st.push({node->right, 1});
      }
      else
      {
        // 3. Postorder: Record value on 3rd visit & pop
        result.postorder.push_back(node->val);
        st.pop();
      }
    }

    return result;
  }
};