/*
814. Binary Tree Pruning
https://leetcode.com/problems/binary-tree-pruning/

Runtime: 4 ms, faster than 63.25% of C++ online submissions
Memory Usage: 9.1 MB, less than 100.00% of C++ online submissions

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
  TreeNode* pruneTree(TreeNode* root) {
    if (root == NULL) {
      return NULL;
    }
    root->left = pruneTree(root->left);
    root->right = pruneTree(root->right);
    if (root->left == NULL && root->right == NULL && root->val == 0) {
      return NULL;
    }
    return root;
  }
};
