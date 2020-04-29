/*
961. N-Repeated Element in Size 2N Array
https://leetcode.com/problems/n-repeated-element-in-size-2n-array/

Runtime: 68 ms, faster than 33.09% of C++ online submissions
Memory Usage: 26.5 MB, less than 5.00% of C++ online submissions

Code written by Siddharth Venu - https://github.com/sidvenu
Licensed under The Unlicense
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  unordered_map<int, int> count;

  int repeat(vector<int>& A, int start, int end) {
    int n = A.size();
    if (start < 0 || end >= n || start > end) {
      return -1;
    }
    /*
    We can also generate a random number for guess. The performance of
    that approach v/s this one depends on the way test cases are generated.
    If the test cases are generated in a truly random fashion, both approaches
    will give about the same performance (this approach will have a slightly
    better runtime, owing to the overhead of a random number generator)
    */
    int guess = (start + end) / 2;
    if (count[A[guess]] > 0) {
      return A[guess];
    }
    count[A[guess]] = 1;
    return max(repeat(A, start, guess - 1), repeat(A, guess + 1, end));
  }

  int repeatedNTimes(vector<int>& A) { return repeat(A, 0, A.size() - 1); }
};
