/*
763. Partition Labels
https://leetcode.com/problems/partition-labels/

Runtime: 64 ms, faster than 5.77% of C++ online submissions
Memory Usage: 11.8 MB, less than 6.45% of C++ online submissions

Code written by Siddharth Venu - https://github.com/sidvenu
Licensed under The Unlicense
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  void partition(vector<int>& partitions, int start, string S) {
    int n = S.length();
    if (start >= n) {
      return;
    }

    unordered_set<char> presentChars, startToEndChars;
    startToEndChars.insert(S[start]);
    int end = start;

    for (int i = start + 1; i < n; i++) {
      presentChars.insert(S[i]);
      if (startToEndChars.find(S[i]) != startToEndChars.end()) {
        end = i;
        startToEndChars.insert(presentChars.begin(), presentChars.end());
        presentChars.clear();
      }
    }
    partitions.push_back(end - start + 1);
    partition(partitions, end + 1, S);
  }

  vector<int> partitionLabels(string S) {
    vector<int> partitions;
    partition(partitions, 0, S);
    return partitions;
  }
};
