/*
832. Flipping an Image
https://leetcode.com/problems/flipping-an-image/

Runtime: 8 ms, faster than 98.28% of C++ online submissions
Memory Usage: 7.2 MB, less than 100.00% of C++ online submissions

Code written by Siddharth Venu - https://github.com/sidvenu
Licensed under The Unlicense
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int flip(int a) { return (a == 1) ? 0 : 1; }
  vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
    int m = A.size(), n = A[0].size();
    for (vector<int>& a : A) {
      for (int i = 0; i < (n + 1) / 2; i++) {
        int j = n - i - 1;
        int temp = a[i];
        a[i] = flip(a[j]);
        a[j] = flip(temp);
      }
    }
    return A;
  }
};
