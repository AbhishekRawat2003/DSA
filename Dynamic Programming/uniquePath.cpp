// find unique path CodeNinja360 question.
// LINK => https://www.naukri.com/code360/problems/unique-paths_1081470
// Recursion-> Memoization-> tabulation;

// Time: O(2^(m+n))
// Space: O(m+n)
#include <iostream>
#include <vector>
using namespace std;

// recursion
// class Solution {
// public:
//   int f(int i, int j) {
//     if (i == 0 && j == 0)
//       return 1;
//     if (i < 0 || j < 0)
//       return 0;
//     int up = f(i - 1, j);
//     int left = f(i, j - 1);

//     return up + left;
//   }
//   int uniquePaths(int m, int n) { return f(m - 1, n - 1); }
// };

// Memoization
// Time: O(m*n)
// Space: O(M+n)+O(n*m)
// class Solution {
// public:
//   int f(int m, int n, vector<vector<int>> &dp) {
//     if (m == 0 && n == 0)
//       return 1;

//     if (m < 0 || n < 0)
//       return 0;

//     if (dp[m][n] != -1)
//       return dp[m][n];

//     return dp[m][n] = f(m - 1, n, dp) + f(m, n - 1, dp);
//   }

//   int uniquePaths(int m, int n) {
//     vector<vector<int>> dp(m, vector<int>(n, -1));
//     return f(m - 1, n - 1, dp);
//   }
// };

// Tabulation
// Time: O()
// Space: O()
class Solution {
public:
  int f(int i, int j, vector<vector<int>> &dp) {

    dp[0][0] = 1;

    for (int row = 0; row <= i; row++) {
      for (int col = 0; col <= j; col++) {

        if (row == 0 && col == 0)
          continue;

        int up = 0, left = 0;

        if (row > 0)
          up = dp[row - 1][col];

        if (col > 0)
          left = dp[row][col - 1];

        dp[row][col] = up + left;
      }
    }

    return dp[i][j];
  }

  int uniquePaths(int m, int n) {
    vector<vector<int>> dp(m, vector<int>(n, 0));
    return f(m - 1, n - 1, dp);
  }
};
int main() {
  int m = 3;
  int n = 3;
  Solution s;
  int result = s.uniquePaths(m, n);
  cout << result << endl;
  return 0;
}