/*
763. Partition Labels
https://leetcode.com/problems/partition-labels/

Runtime: 4 ms, faster than 93.38% of C++ online submissions
Memory Usage: 7.4 MB, less than 100.00% of C++ online submissions

Code written by Siddharth Venu - https://github.com/sidvenu
Licensed under The Unlicense
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  void partition(vector<int>& partitions, int start, int endIndexes[],
                 string S) {
    int n = S.length();
    if (start >= n) {
      return;
    }
    int end = endIndexes[S[start] - 'a'];
    for (int i = start + 1; i < end; i++) {
      end = max(end, endIndexes[S[i] - 'a']);
    }
    partitions.push_back(end - start + 1);

    partition(partitions, end + 1, endIndexes, S);
  }

  vector<int> partitionLabels(string S) {
    int index[26] = {-1};
    int n = S.length();
    for (int i = 0; i < n; i++) {
      index[S[i] - 'a'] = i;
    }
    vector<int> partitions;
    partition(partitions, 0, index, S);
    return partitions;
  }
};
