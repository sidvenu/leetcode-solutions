/*
1309. Decrypt String from Alphabet to Integer Mapping
https://leetcode.com/problems/decrypt-string-from-alphabet-to-integer-mapping/

Runtime: 0 ms, faster than 100.00% of C++ online submissions
Memory Usage: 6.3 MB, less than 100.00% of C++ online submissions

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
