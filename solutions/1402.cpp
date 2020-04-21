/*
1402. Reducing Dishes
https://leetcode.com/problems/reducing-dishes/

Code written by Siddharth Venu - https://github.com/sidvenu
Licensed under The Unlicense
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int binSearch(vector<int>& s, int e) {
    int low = 0, high = s.size() - 1, guess = (high + low) / 2;
    while (!((guess <= 0 || s[guess - 1] < e) && s[guess] >= e) &&
           low <= high) {
      if (guess <= 0 || s[guess - 1] < e) {
        low = guess + 1;
      }
      if (s[guess] >= e) {
        high = guess - 1;
      }
      guess = (high + low) / 2;
    }
    if (low <= high) return guess;
    return -1;
  }
  int maxSatisfaction(vector<int>& s) {
    sort(s.begin(), s.end());
    int maxS = s[s.size() - 1];
    if (maxS <= 0) {
      return 0;
    }
    int su = maxS, i = s.size() - 2;
    for (i = s.size() - 2; i >= 0; i--) {
      if (su + s[i] >= 0)
        su += s[i];
      else
        break;
    }
    int start = i + 1;

    // My initial approach (wrong). Guess why?
    // ------------------------------------------
    // int positiveStart = binSearch(s, 0);
    // if(positiveStart == -1) {
    //     return 0;
    // }
    // int sumPositive = 0;
    // for(int i = positiveStart; i<s.size(); i++) {
    //     sumPositive += s[i];
    // }
    // int start = binSearch(s, -sumPositive + 1);

    int ret = 0;
    for (i = start; i < s.size(); i++) {
      ret += (i - start + 1) * s[i];
    }
    return ret;
  }
};
