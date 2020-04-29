/*
1381. Design a Stack With Increment Operation
https://leetcode.com/problems/design-a-stack-with-increment-operation/

Runtime: 68 ms, faster than 17.31% of C++ online submissions
Memory Usage: 21.1 MB, less than 100.00% of C++ online submissions

Code written by Siddharth Venu - https://github.com/sidvenu
Licensed under The Unlicense
*/

#include <bits/stdc++.h>
using namespace std;

class CustomStack {
 public:
  int n, maxSize;
  vector<int> arr, inc;

  CustomStack(int maxSize) {
    this->maxSize = maxSize;
    n = 0;
  }

  void push(int x) {
    if (n < maxSize) {
      arr.push_back(x);
      inc.push_back(0);
      n++;
    }
  }

  int pop() {
    if (n > 0) {
      int e = arr[n - 1];
      arr.pop_back();
      int i = inc[n - 1];
      inc.pop_back();
      if (n >= 2) inc[n - 2] += i;
      n--;
      return e + i;
    }
    return -1;
  }

  void increment(int k, int val) {
    if (n > 0 && k > 0) inc[min(n - 1, k - 1)] += val;
  }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */
