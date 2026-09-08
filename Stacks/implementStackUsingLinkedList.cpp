#include <bits/stdc++.h>
using namespace std;

//  Structure of linked list Node
class Node
{
public:
  int data;
  Node *next;

  Node(int val)
  {
    data = val;
    next = nullptr;
  }
};

class myStack
{
private:
  Node *top;
  int currentSize;

public:
  myStack()
  {
    // Initialize your data members
    top = NULL;
    currentSize = 0;
  }

  bool isEmpty()
  {
    // check if the stack is empty
    return top == NULL;
  }

  void push(int x)
  {
    // Adds an element x at the top of the stack
    currentSize++;
    if (top == NULL)
    {
      top = new Node(x);
    }
    else
    {
      Node *temp = new Node(x);
      temp->next = top;
      top = temp;
    }
  }

  void pop()
  {
    // Removes the top element of the stack
    if (top != NULL)
    {
      currentSize--;
      Node *temp = top;
      top = top->next;
      delete temp;
    }
  }

  int peek()
  {
    // Returns the top element of the stack
    // If stack is empty, return -1
    if (top == NULL)
      return -1;
    return top->data;
  }

  int size()
  {
    // Returns the current size of the stack
    return currentSize;
  }
};

// Time Complexity: O(1) for all operations