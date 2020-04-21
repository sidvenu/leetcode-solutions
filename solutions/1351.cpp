/*
1351. Count Negative Numbers in a Sorted Matrix
https://leetcode.com/problems/count-negative-numbers-in-a-sorted-matrix/

Code written by Siddharth Venu - https://github.com/sidvenu
Licensed under The Unlicense
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int countt(vector<vector<int>> &grid, int mS, int mE, int nS, int nE) {
    if (mS > mE || nS > nE || mS < 0 || nS < 0 || mE >= grid.size() ||
        nE >= grid[0].size()) {
      return 0;
    }
    int numRows = mE - mS + 1;
    int numCols = nE - nS + 1;

    int rLow = mS, rHigh = mE;
    int rGuess = (rLow + rHigh) / 2;
    while (!(grid[rGuess][nS] < 0 &&
             (rGuess <= mS || grid[rGuess - 1][nS] >= 0)) &&
           rLow <= rHigh) {
      if (grid[rGuess][nS] < 0) {
        rHigh = rGuess;
      }
      if (rGuess <= 0 || grid[rGuess - 1][nS] >= 0) {
        rLow = rGuess + 1;
      }
      rGuess = (rLow + rHigh) / 2;
    }
    int countNeg = 0;
    if (rLow <= rHigh) {
      countNeg += (mE - rGuess + 1) * numCols;
    } else
      rGuess = mE + 1;

    int cLow = nS, cHigh = nE;
    int cGuess = (cLow + cHigh) / 2;
    while (!(grid[mS][cGuess] < 0 &&
             (cGuess <= nS || grid[mS][cGuess - 1] >= 0)) &&
           cLow <= cHigh) {
      if (grid[mS][cGuess] < 0) {
        cHigh = cGuess;
      }
      if (cGuess <= 0 || grid[mS][cGuess - 1] >= 0) {
        cLow = cGuess + 1;
      }
      cGuess = (cLow + cHigh) / 2;
    }
    if (cLow <= cHigh) {
      countNeg += (nE - cGuess + 1) * (rGuess - mS);
    } else
      cGuess = nE + 1;

    countNeg += countt(grid, mS + 1, rGuess - 1, nS + 1, cGuess - 1);

    return countNeg;
  }

  int countNegatives(vector<vector<int>> &grid) {
    return countt(grid, 0, grid.size() - 1, 0, grid[0].size() - 1);
  }
};
