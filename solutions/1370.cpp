/*
1370. Increasing Decreasing String
https://leetcode.com/problems/increasing-decreasing-string/

Code written by Siddharth Venu - https://github.com/sidvenu
Licensed under The Unlicense
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  char getAlpha(int d) { return (char)('a' + d - 1); }
  int getDigit(char d) { return (int)(d - '0'); }
  string freqAlphabets(string s) {
    int n = s.length();
    string outp = "";
    for (int i = 0; i < n;) {
      if (i < n - 2 && s[i + 2] == '#') {
        int d = 10 * getDigit(s[i]) + getDigit(s[i + 1]);
        outp += getAlpha(d);
        i += 3;
      } else {
        outp += getAlpha(getDigit(s[i]));
        i++;
      }
    }
    return outp;
  }
};
