/*
617. Merge Two Binary Trees
https://leetcode.com/problems/merge-two-binary-trees/

Runtime: 48 ms, faster than 93.87% of C++ online submissions
Memory Usage: 21.9 MB, less than 19.44% of C++ online submissions

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
      node = t1;
      node->val += t2->val;
      node->left = mergeTrees(t1->left, t2->left);
      node->right = mergeTrees(t1->right, t2->right);
    } else if (t1 != NULL) {
      node = t1;
    } else if (t2 != NULL) {
      node = t2;
    }
    return node;
  }
};
