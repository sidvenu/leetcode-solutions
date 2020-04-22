/*
1079. Letter Tile Possibilities
https://leetcode.com/problems/letter-tile-possibilities/

Runtime: 0 ms, faster than 100.00% of C++ online submissions
Memory Usage: 6 MB, less than 100.00% of C++ online submissions

Code written by Siddharth Venu - https://github.com/sidvenu
Licensed under The Unlicense
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int facCache[8];
  int fac(int n) {
    if (n <= 1) {
      return 1;
    }
    if (facCache[n] != 0) {
      return facCache[n];
    }
    int r = n * fac(n - 1);
    facCache[n] = r;
    return r;
  }

  int permutationWithRepetition(vector<int>& v) {
    int n = 0;
    for (int a : v) {
      n += a;
    }
    int p = fac(n);
    for (int a : v) {
      p /= fac(a);
    }
    return p;
  }

  bool increment(int pos, vector<int>& v, vector<int>& count) {
    if (pos < 0) {
      return false;
    }

    int carry = (v[pos] + 1) / (count[pos] + 1);
    v[pos] = (v[pos] + 1) % (count[pos] + 1);
    if (carry == 1) {
      bool success = increment(pos - 1, v, count);
      return success;
    }
    return true;
  }

  int numTilePossibilities(string tiles) {
    int n = tiles.length();
    vector<int> count(26, 0);
    for (char c : tiles) {
      count[c - 'A']++;
    }

    count.erase(remove(count.begin(), count.end(), 0), count.end());

    int possibilities = 0;
    vector<int> v(count.size(), 0);

    // for all possible combinations of count, add each combination's
    // permutation with repetition value to total possibilities
    while (increment(v.size() - 1, v, count)) {
      possibilities += permutationWithRepetition(v);
    }
    return possibilities;
  }
};
