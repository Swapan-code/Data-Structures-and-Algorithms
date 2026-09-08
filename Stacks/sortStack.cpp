// https://www.geeksforgeeks.org/problems/sort-a-stack/1

#include <bits/stdc++.h>
using namespace std;

// Approach 1: Using Auxiliary Stack
// Time Complexity: O(N^2)
// Space Complexity: O(N)
void sortStack(stack<int> &st)
{
  stack<int> temp;
  while (!st.empty())
  {
    int ele = st.top();
    st.pop();

    // insert at correct position in s2
    while (!temp.empty() && temp.top() > ele)
    {
      st.push(temp.top());
      temp.pop();
    }
    temp.push(ele);
  }

  st = temp;
}

// Approach 2: Pure Recursion (In-place)
// Time Complexity: O(N^2)
// Space Complexity: O(N)
void insertInSortedStack(stack<int> &st, int ele)
{
  if (st.empty() || st.top() <= ele)
  {
    st.push(ele);
    return;
  }

  int temp = st.top();
  st.pop();
  insertInSortedStack(st, ele);
  st.push(temp);
}

void sortStack(stack<int> &st)
{
  if (st.size() == 1)
    return;
  int ele = st.top();
  st.pop();
  sortStack(st);
  insertInSortedStack(st, ele);
}

// Approach 3: Using Vector Sorting
// Time Complexity: O(N logN)
// Space Complexity: O(N)
void sortStack(stack<int> &st)
{
  vector<int> v;
  while (!st.empty())
  {
    v.push_back(st.top());
    st.pop();
  }

  sort(v.begin(), v.end());
  for (auto i : v)
    st.push(i);
}