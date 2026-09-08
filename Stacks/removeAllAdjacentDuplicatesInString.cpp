//

#include <bits/stdc++.h>
using namespace std;

// Approach 1: Using Explicit Stack
// Time Complexity: O(N)
// Space Complexity: O(N)
string removeDuplicates(string s)
{
  stack<char> st;
  for (auto i : s)
  {
    if (st.empty() || st.top() != i)
      st.push(i);
    else
      st.pop();
  }

  string res = "";
  while (!st.empty())
  {
    res += st.top();
    st.pop();
  }

  reverse(res.begin(), res.end());
  return res;
}

// Approach 2: Using Output String as Stack
// Time Complexity: O(N)
// Space Complexity: O(1) <- Auxiliary Space
string removeDuplicates(string s)
{
  string res = "";
  for (auto i : s)
  {
    if (res.empty() || res.back() != i)
      res += i;
    else
      res.pop_back();
  }

  return res;
}

// Approach 3: Simulated Stack In-Place
// Time Complexity: O(N)
// Space Complexity: O(1)
string removeDuplicates(string s)
{
  int idx = 0;
  for (auto i : s)
  {
    if (idx > 0 && s[idx - 1] == i)
      idx--;
    else
      s[idx++] = i;
  }
  // return s.substr(0, idx);

  s.resize(idx); // Truncate in-place, avoiding a new string allocation
  return s;
}
