#include <bits/stdc++.h>
using namespace std;

class ArrayStack
{
private:
  int *stackArray; // Array to hold elements
  int capacity;    // Maximum capacity
  int topIndex;    // Index of top element

public:
  // Constructor
  ArrayStack(int size)
  {
    capacity = size;
    stackArray = new int[capacity];
    topIndex = -1; // Initialize stack as empty
  }

  // Destructor
  ~ArrayStack()
  {
    delete[] stackArray;
  }

  // Pushes element x
  void push(int x)
  {
    if (topIndex >= capacity - 1)
    {
      cout << "Stack overflow" << endl;
      return;
    }
    stackArray[++topIndex] = x;
  }

  // Removes and returns top element
  int pop()
  {
    if (isEmpty())
    {
      cout << "Stack is empty" << endl;
      return -1;
    }
    return stackArray[topIndex--];
  }

  // Returns top element
  int top()
  {
    if (isEmpty())
    {
      cout << "Stack is empty" << endl;
      return -1;
    }
    return stackArray[topIndex];
  }

  bool isEmpty()
  {
    return topIndex == -1;
  }

  bool isFull()
  {
    return topIndex == capacity - 1;
  }
};

// Time Complexity: O(1) for all operations