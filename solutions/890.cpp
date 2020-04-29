/*
890. Find and Replace Pattern
https://leetcode.com/problems/find-and-replace-pattern/

Runtime: 4 ms, faster than 86.48% of C++ online submissions
Memory Usage: 7.9 MB, less than 100.00% of C++ online submissions

Code written by Siddharth Venu - https://github.com/sidvenu
Licensed under The Unlicense
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
    int n = pattern.length();
    vector<string> v;
    for (string word : words) {
      char m[26] = {0};
      int p[26] = {0};
      bool incl = true;
      for (int i = 0; i < n; i++) {
        char wc = word[i], wp = pattern[i];
        int alphaIndex = wp - 'a';
        if (m[alphaIndex] == 0 && p[wc - 'a'] == 0) {
          m[alphaIndex] = wc;
          p[wc - 'a'] = 1;
        } else if (m[alphaIndex] != wc) {
          incl = false;
          break;
        }
      }
      if (incl) {
        v.push_back(word);
      }
    }
    return v;
  }
};
