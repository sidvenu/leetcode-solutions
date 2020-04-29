/*
1325. Delete Leaves With a Given Value
https://leetcode.com/problems/delete-leaves-with-a-given-value/

Runtime: 16 ms, faster than 96.58% of C++ online submissions
Memory Usage: 18.8 MB, less than 100.00% of C++ online submissions

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
  TreeNode* removeLeafNodes(TreeNode* root, int target) {
    if (root == NULL) return NULL;
    root->left = removeLeafNodes(root->left, target);
    root->right = removeLeafNodes(root->right, target);
    if (root->left == NULL && root->right == NULL && root->val == target)
      return NULL;
    return root;
  }
};
