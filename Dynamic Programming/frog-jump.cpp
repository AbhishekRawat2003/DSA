// frog jump https://www.naukri.com/code360/problems/frog-jump_3621012
#include <iostream>
#include <vector>
using namespace std;
// class Solution {
// public:
//   // Memoization
//   int frogJump(int n, vector<int> &heights, vector<int> &dp) {
//     if (n == 0) {
//       return 0;
//     } else if (n == 1) {
//       return abs(heights[1] - heights[0]);
//     }
//     if (dp[n] != -1) {
//       return dp[n];
//     }
//     int fromOne =
//         frogJump(n - 1, heights, dp) + abs(heights[n] - heights[n - 1]);
//     int fromSecond =
//         frogJump(n - 2, heights, dp) + abs(heights[n] - heights[n - 2]);
//     return dp[n] = min(fromOne, fromSecond);
//   }
// };
// int main() {
//   vector<int> heights = {10, 20, 30, 10};
//   int n = 4;
//   vector<int> dp(n, -1);
//   Solution s;
//   int res = s.frogJump(n - 1, heights, dp);
//   cout << res << endl;
//   return 0;
// }

// tabulation================>

class Solution {
public:
  int frogJump(int n, vector<int> &heights) {
    vector<int> dp(n, 0);
    dp[0] = 0;
    dp[1] = abs(heights[1] - heights[0]);

    for (int i = 2; i < n; i++) {
      int fromOne = dp[i - 1] + abs(heights[i] - heights[i - 1]);
      int fromSecond = dp[i - 2] + abs(heights[i] - heights[i - 2]);
      dp[i] = min(fromOne, fromSecond);
    }
    return dp[n - 1];
  }
};
int main() {
  vector<int> heights = {10, 20, 30, 10};
  int n = 4;
  Solution s;
  int res = s.frogJump(n, heights);
  cout << res << endl;
  return 0;
}