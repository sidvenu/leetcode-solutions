/*
950. Reveal Cards In Increasing Order
https://leetcode.com/problems/reveal-cards-in-increasing-order/

Runtime: 8 ms, faster than 98.44% of C++ online submissions
Memory Usage: 6.6 MB, less than 100.00% of C++ online submissions

Code written by Siddharth Venu - https://github.com/sidvenu
Licensed under The Unlicense
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  void deckF(vector<int>& r, vector<int>& deck, int start, int step, int count,
             int dIndex) {
    /*
      n%2==0
      a0 a1 a2 a3 a4 a5 a6 a7 a8 ... an-1 - start 0, step 1
      a1 a3 a5 a7 a9 a11 a13 ... an-1 - start 1, step 2
      a7 a11 a15 ... an-3 a3 - start 7, step 4

      n%2!=0
      a0 a1 a2 a3 a4 a5 a6 a7 a8 ... an-1 - start 0, step 1
      a3 a5 a7 ... an-2 a1 - start 3, step 2
      a9, a13 ... a5
   */
    int n = r.size();
    if (dIndex >= n || count <= 0) {
      return;
    }
    int acCount = ((count % 2 == 0) ? count : (count + 1)) / 2;
    int c = 0;

    for (int i = start; i < n && c < acCount; i += 2 * step, c++) {
      r[i] = deck[dIndex++];
    }
    if (start - step >= 0 && r[start - step] == 0 && c < acCount)
      r[start - step] = deck[dIndex++];

    int newStart = start + step * ((count % 2 == 0) ? 1 : 3);
    int newCount = ((count % 2 == 0) ? count : (count - 1)) / 2;

    deckF(r, deck, newStart, step * 2, newCount, dIndex);
  }

  vector<int> deckRevealedIncreasing(vector<int>& deck) {
    int n = deck.size();
    sort(deck.begin(), deck.end());
    vector<int> r(n, 0);
    deckF(r, deck, 0, 1, n, 0);

    return r;
  }
};
