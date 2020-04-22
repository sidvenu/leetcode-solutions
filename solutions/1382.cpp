/*
1382. Balance a Binary Search Tree
https://leetcode.com/problems/generate-a-string-with-characters-that-have-odd-counts/

Runtime: 176 ms, faster than 69.19% of C++ online submissions
Memory Usage: 35 MB, less than 100.00% of C++ online submissions

Disclaimer: I was stuck in this problem for a while, and referred to
GeeksforGeeks to know the algorithm (but not the code). Here's the URL for the
post: https://www.geeksforgeeks.org/convert-normal-bst-balanced-bst/

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
  void buildArrayFromBST(TreeNode* node, vector<TreeNode*>& nodes) {
    if (node == NULL) {
      return;
    }
    buildArrayFromBST(node->left, nodes);
    nodes.push_back(node);
    buildArrayFromBST(node->right, nodes);
  }

  TreeNode* buildBalancedBSTFromArray(int start, int end,
                                      vector<TreeNode*>& nodes) {
    if (start > end) {
      return NULL;
    }
    int mid = (start + end) / 2;
    TreeNode* node = nodes[mid];
    node->left = buildBalancedBSTFromArray(start, mid - 1, nodes);
    node->right = buildBalancedBSTFromArray(mid + 1, end, nodes);
    return node;
  }

  TreeNode* balanceBST(TreeNode* root) {
    vector<TreeNode*> nodes;
    buildArrayFromBST(root, nodes);
    return buildBalancedBSTFromArray(0, nodes.size() - 1, nodes);
  }
};
