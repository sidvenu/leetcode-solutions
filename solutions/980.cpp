/*
980. Unique Paths III
https://leetcode.com/problems/unique-paths-iii/

Runtime: 40 ms, faster than 20.60% of C++ online submissions
Memory Usage: 28.8 MB, less than 100.00% of C++ online submissions

Code written by Siddharth Venu - https://github.com/sidvenu
Licensed under The Unlicense
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  bool canMove(int i, int j, vector<vector<int>>& grid,
               vector<vector<int>>& check, int m, int n) {
    return i >= 0 && i < m && j >= 0 && j < n && check[i][j] != 1 &&
           grid[i][j] != -1;
  }

  bool validPath(vector<vector<int>>& grid, vector<vector<int>>& check) {
    int m = grid.size(), n = grid[0].size();
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (grid[i][j] == 0 && check[i][j] == 0) {
          return false;
        }
      }
    }
    return true;
  }

  int uniquePathsIII(vector<vector<int>>& grid, int i, int j,
                     vector<vector<int>>& check) {
    int m = grid.size(), n = grid[0].size();
    if (grid[i][j] == 2) {
      if (validPath(grid, check)) return 1;
      return 0;
    }

    int paths = 0;
    vector<vector<int>> checkCopy;
    check[i][j] = 1;

    if (canMove(i + 1, j, grid, check, m, n)) {
      checkCopy = check;
      paths += uniquePathsIII(grid, i + 1, j, checkCopy);
    }
    if (canMove(i - 1, j, grid, check, m, n)) {
      checkCopy = check;
      paths += uniquePathsIII(grid, i - 1, j, checkCopy);
    }
    if (canMove(i, j + 1, grid, check, m, n)) {
      checkCopy = check;
      paths += uniquePathsIII(grid, i, j + 1, checkCopy);
    }
    if (canMove(i, j - 1, grid, check, m, n)) {
      checkCopy = check;
      paths += uniquePathsIII(grid, i, j - 1, checkCopy);
    }

    return paths;
  }

  int uniquePathsIII(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size();
    vector<vector<int>> check(m, vector<int>(n, 0));
    int i, j;
    for (i = 0; i < m; i++) {
      for (j = 0; j < n && grid[i][j] != 1; j++)
        ;

      if (j < n && grid[i][j] == 1) {
        break;
      }
    }
    return uniquePathsIII(grid, i, j, check);
  }
};
