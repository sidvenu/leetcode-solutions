/*
1305. All Elements in Two Binary Search Trees
https://leetcode.com/problems/all-elements-in-two-binary-search-trees/

Runtime: 292 ms, faster than 50.29% of C++ online submissions
Memory Usage: 53.7 MB, less than 100.00% of C++ online submissions

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
  int countNodeElements(TreeNode* node) {
    if (node == NULL) return 0;
    return 1 + countNodeElements(node->left) + countNodeElements(node->right);
  }
  void ascendingElements(TreeNode* node, vector<int>& e) {
    if (node == NULL) return;
    ascendingElements(node->left, e);
    e.push_back(node->val);
    ascendingElements(node->right, e);
  }
  vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
    int m1 = countNodeElements(root1), m2 = countNodeElements(root2);
    vector<int> arr1, arr2;

    // allocate enough memory before-hand to prevent reallocations
    arr1.reserve(m1);
    arr2.reserve(m2);

    // get elements of both trees in asc order
    ascendingElements(root1, arr1);
    ascendingElements(root2, arr2);

    // merge em both
    int pos1 = 0, pos2 = 0, pos = 0;

    vector<int> arr(m1 + m2, 0);

    for (; pos1 < m1 || pos2 < m2; pos++) {
      if (pos1 < m1 && pos2 < m2) {
        if (arr1[pos1] <= arr2[pos2]) {
          arr[pos] = arr1[pos1++];
        } else {
          arr[pos] = arr2[pos2++];
        }
      } else if (pos1 < m1) {
        arr[pos] = arr1[pos1++];
      } else {
        arr[pos] = arr2[pos2++];
      }
    }

    return arr;
  }
};
