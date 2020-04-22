/*
1347. Minimum Number of Steps to Make Two Strings Anagram
https://leetcode.com/problems/minimum-number-of-steps-to-make-two-strings-anagram/

Runtime: 92 ms, faster than 62.34% of C++ online submissions
Memory Usage: 16.7 MB, less than 100.00% of C++ online submissions

Code written by Siddharth Venu - https://github.com/sidvenu
Licensed under The Unlicense
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  /*
  l - 1, e - 3, t - 1, c - 1, o - 1, d - 1
  p - 1, r - 1, a - 1, e - 1, t - 1, i - 1, c - 2
  */
  int minSteps(string s, string t) {
    int sCount[26] = {0}, tCount[26] = {0};
    for (char c : s) {
      sCount[c - 'a']++;
    }
    for (char c : t) {
      tCount[c - 'a']++;
    }
    int count = 0;
    for (int i = 0; i < 26; i++) {
      count += abs(sCount[i] - tCount[i]);
    }
    count /= 2;
    return count;
  }
};
