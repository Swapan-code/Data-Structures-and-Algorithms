#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
  int data;
  Node *left;
  Node *right;

  Node(int val)
  {
    data = val;
    left = nullptr;
    right = nullptr;
  }
};

// Iterative Approach
// Time Complexity: O(N)
// Space Complexity: O(N)
class Solution
{
public:
  Node *buildTree(vector<int> &nodes)
  {
    int n = nodes.size();
    queue<Node *> q;
    int i = 0;

    Node *root = new Node(nodes[i++]);
    q.push(root);

    while (i < n)
    {
      Node *parent = q.front();
      q.pop();

      parent->left = new Node(nodes[i++]);
      q.push(parent->left);

      if (i < n)
      {
        parent->right = new Node(nodes[i++]);
        q.push(parent->right);
      }
    }

    return root;
  }
};

// Recursive Approach
// Time Complexity: O(N)
// Space Complexity: O(N)
class Solution
{
private:
  Node *recursiveBuild(int i, vector<int> &nodes)
  {
    if (i >= nodes.size())
      return NULL;

    Node *root = new Node(nodes[i]);

    root->left = recursiveBuild(2 * i + 1, nodes);
    root->right = recursiveBuild(2 * i + 2, nodes);
    return root;
  }

public:
  Node *buildTree(vector<int> &nodes)
  {
    return recursiveBuild(0, nodes);
  }
};