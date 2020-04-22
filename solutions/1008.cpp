/*
1008. Construct Binary Search Tree from Preorder Traversal
https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/

Runtime: 8 ms, faster than 40.33% of C++ online submissions
Memory Usage: 11.6 MB, less than 28.57% of C++ online submissions

Code written by Siddharth Venu - https://github.com/sidvenu
Licensed under The Unlicense
*/

#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
 public:
  TreeNode* bstFromPreorder(vector<int>& preorder, int i, int min, int max) {
    if (i >= preorder.size()) return NULL;
    if (min < preorder[i] && preorder[i] < max) {
      TreeNode* node = new TreeNode(preorder[i]);
      node->left = bstFromPreorder(preorder, i + 1, min, preorder[i]);
      node->right = bstFromPreorder(preorder, i + 1, preorder[i], max);
      return node;
    }
    return bstFromPreorder(preorder, i + 1, min, max);
  }

  TreeNode* bstFromPreorder(vector<int>& preorder) {
    return bstFromPreorder(preorder, 0, INT_MIN, INT_MAX);
  }
};
