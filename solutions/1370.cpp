/*
1370. Increasing Decreasing String
https://leetcode.com/problems/increasing-decreasing-string/

Runtime: 4 ms, faster than 98.59% of C++ online submissions
Memory Usage: 7.5 MB, less than 100.00% of C++ online submissions

Code written by Siddharth Venu - https://github.com/sidvenu
Licensed under The Unlicense
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  string sortString(string s) {
    int countAlpha[26] = {0};
    for (int i = 0; i < s.length(); i++) {
      countAlpha[s[i] - 'a']++;
    }
    bool shouldContinue = true;
    string o = "";
    while (shouldContinue) {
      shouldContinue = false;
      for (int i = 0; i < 26; i++) {
        char c = i + 'a';
        if (countAlpha[i] > 0) {
          o += c;
          countAlpha[i]--;
          shouldContinue = true;
        }
      }
      for (int i = 25; i >= 0; i--) {
        char c = i + 'a';
        if (countAlpha[i] > 0) {
          o += c;
          countAlpha[i]--;
          shouldContinue = true;
        }
      }
    }
    return o;
  }
};
