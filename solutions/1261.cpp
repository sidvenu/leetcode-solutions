/*
1261. Find Elements in a Contaminated Binary Tree
https://leetcode.com/problems/find-elements-in-a-contaminated-binary-tree/

Runtime: 56 ms, faster than 59.59% of C++ online submissions
Memory Usage: 33.5 MB, less than 100.00% of C++ online submissions

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
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class FindElements {
 public:
  TreeNode* root;
  unordered_map<int, bool> exists;

  FindElements(TreeNode* root) {
    root->val = 0;
    exists[0] = true;
    recover(root);
    this->root = root;
  }

  void recover(TreeNode* node) {
    if (node->left != NULL) {
      int val = 2 * (node->val) + 1;
      node->left->val = val;
      exists[val] = true;
      recover(node->left);
    }
    if (node->right != NULL) {
      int val = 2 * (node->val) + 2;
      node->right->val = val;
      exists[val] = true;
      recover(node->right);
    }
  }

  bool find(int target) { return exists[target]; }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */
