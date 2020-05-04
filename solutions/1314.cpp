/*
1314. Matrix Block Sum
https://leetcode.com/problems/matrix-block-sum/

Runtime: 16 ms, faster than 98.11% of C++ online submissions
Memory Usage: 9.9 MB, less than 100.00% of C++ online submissions

Code written by Siddharth Venu - https://github.com/sidvenu
Licensed under The Unlicense
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int getLowerBound(int e) { return (e >= 0) ? e : 0; }
  int getHigherBound(int e, int n) { return (e < n) ? e : n - 1; }
  vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
    int m = mat.size(), n = mat[0].size();
    vector<vector<int>> answer(m, vector(n, 0));
    vector<vector<int>> sumM(m, vector(n, 0)), sumN(m, vector(n, 0));

    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        sumN[i][j] += mat[i][j];
        if (j > 0) sumN[i][j] += sumN[i][j - 1];
        sumM[i][j] += mat[i][j];
        if (i > 0) sumM[i][j] += sumM[i - 1][j];
      }
    }

    for (int i = 0; i < m && i <= k; i++) {
      for (int j = 0; j < n && j <= k; j++) {
        answer[0][0] += mat[i][j];
      }
    }

    for (int i = 0; i < m; i++) {
      int topBound = i - k, bottomBound = i + k;

      if (i != 0) {
        int leftBound = 0, rightBound = k;
        answer[i][0] = answer[i - 1][0];

        if (topBound - 1 >= 0) {
          int topBoundSum = sumN[topBound - 1][getHigherBound(rightBound, n)];
          answer[i][0] -= topBoundSum;
        }

        if (bottomBound < m) {
          int bottomBoundSum = sumN[bottomBound][getHigherBound(rightBound, n)];
          answer[i][0] += bottomBoundSum;
        }
      }

      for (int j = 1; j < n; j++) {
        answer[i][j] = answer[i][j - 1];
        int leftBound = j - k, rightBound = j + k;

        if (leftBound - 1 >= 0) {
          int leftBoundSum =
              sumM[getHigherBound(bottomBound, m)][leftBound - 1];
          if (topBound > 0)
            leftBoundSum -= sumM[getLowerBound(topBound - 1)][leftBound - 1];
          answer[i][j] -= leftBoundSum;
        }

        if (rightBound < n) {
          int rightBoundSum = sumM[getHigherBound(bottomBound, m)][rightBound];
          if (topBound > 0)
            rightBoundSum -= sumM[getLowerBound(topBound - 1)][rightBound];
          answer[i][j] += rightBoundSum;
        }
      }
    }
    return answer;
  }
};
