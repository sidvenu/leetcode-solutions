/*
1374. Generate a String With Characters That Have Odd Counts
https://leetcode.com/problems/generate-a-string-with-characters-that-have-odd-counts/

Runtime: 0 ms, faster than 100.00% of C++ online submissions
Memory Usage: 6.5 MB, less than 100.00% of C++ online submissions

Code written by Siddharth Venu - https://github.com/sidvenu
Licensed under The Unlicense
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  string generateTheString(int n) {
    string out(n - 1, 'a');
    if (n % 2 == 0) {
      out = out + 'b';
    } else
      out = out + 'a';
    return out;
  }
};
