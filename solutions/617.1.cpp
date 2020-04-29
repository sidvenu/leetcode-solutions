/*
617. Merge Two Binary Trees
https://leetcode.com/problems/merge-two-binary-trees/

Runtime: 56 ms, faster than 70.91% of C++ online submissions
Memory Usage: 32.5 MB, less than 5.55% of C++ online submissions

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
class Solution {
 public:
  TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
    TreeNode* node = NULL;
    if (t1 != NULL && t2 != NULL) {
      node = new TreeNode(t1->val + t2->val);
      node->left = mergeTrees(t1->left, t2->left);
      node->right = mergeTrees(t1->right, t2->right);
    } else if (t1 != NULL) {
      node = new TreeNode(t1->val);
      node->left = mergeTrees(t1->left, NULL);
      node->right = mergeTrees(t1->right, NULL);
    } else if (t2 != NULL) {
      node = new TreeNode(t2->val);
      node->left = mergeTrees(NULL, t2->left);
      node->right = mergeTrees(NULL, t2->right);
    }
    return node;
  }
};
