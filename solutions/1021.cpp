/*
1021. Remove Outermost Parentheses
https://leetcode.com/problems/remove-outermost-parentheses/

Code written by Siddharth Venu - https://github.com/sidvenu
Licensed under The Unlicense
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  string removeOuterParentheses(string S) {
    int count = 0;
    int start = 0;
    string result = "";
    for (int i = 0; i < S.length(); i++) {
      if (S[i] == '(') {
        count++;
      } else
        count--;
      if (count == 0) {
        int end = i;
        int lenn = end - start + 1;
        result += (S.substr(start + 1, lenn - 2));
        start = end + 1;
      }
    }
    return result;
  }
};
