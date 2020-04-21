/*
1304. Find N Unique Integers Sum up to Zero
https://leetcode.com/problems/find-n-unique-integers-sum-up-to-zero/

Code written by Siddharth Venu - https://github.com/sidvenu
Licensed under The Unlicense
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  vector<int> sumZero(int n) {
    vector<int> arr;
    if (n % 2 == 1) arr.push_back(0);
    for (int i = 0; i < n / 2; i++) {
      arr.push_back(i + 1);
      arr.push_back(-i - 1);
    }
    return arr;
  }
};
