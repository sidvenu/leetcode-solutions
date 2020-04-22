/*
905. Sort Array By Parity
https://leetcode.com/problems/sort-array-by-parity/

Runtime: 24 ms, faster than 95.15% of C++ online submissions
Memory Usage: 7.4 MB, less than 100.00% of C++ online submissions

Code written by Siddharth Venu - https://github.com/sidvenu
Licensed under The Unlicense
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
  }

  vector<int> sortArrayByParity(vector<int> &A) {
    int n = A.size();
    int start = 0, end = n - 1;
    while (true) {
      while (start <= end && A[start] % 2 == 0) {
        start++;
      }
      while (start <= end && A[end] % 2 == 1) {
        end--;
      }
      if (start <= end) {
        swap(A[start], A[end]);
      } else
        break;
    }
    return A;
  }
};
