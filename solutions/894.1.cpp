/*
894. All Possible Full Binary Trees
https://leetcode.com/problems/all-possible-full-binary-trees/

Runtime: 188 ms, faster than 58.79% of C++ online submissions
Memory Usage: 31.7 MB, less than 50.00% of C++ online submissions

Code written by Siddharth Venu - https://github.com/sidvenu
Licensed under The Unlicense
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  unordered_map<int, vector<TreeNode*>> m;

  vector<TreeNode*> allPossibleFBT(int N) {
    if (N % 2 == 0 || N <= 0) {
      return vector<TreeNode*>();
    }
    if (N == 1) {
      TreeNode* node = new TreeNode(0);
      return vector<TreeNode*>{node};
    }
    if (m.count(N) >= 1) {
      return m[N];
    }
    vector<TreeNode*> nodes;

    for (int l = 1; l < N - 1; l += 2) {
      int r = N - l - 1;
      vector<TreeNode*> lnodes = allPossibleFBT(l), rnodes = allPossibleFBT(r);
      for (TreeNode* lnode : lnodes) {
        for (TreeNode* rnode : rnodes) {
          TreeNode* newroot = new TreeNode(0);
          newroot->left = lnode;
          newroot->right = rnode;
          nodes.push_back(newroot);
        }
      }
    }
    m[N] = nodes;
    return nodes;
  }
};
