#include <climits>
#include <iostream>
#include <vector>
using namespace std;

// class Solution {
// public:
//   int solve(int i, int j, vector<vector<int>> &nums) {
//     if (i == 0 && j == 0)
//       return nums[i][j];

//     int up = INT_MAX;
//         int left = INT_MAX;

//         if (i > 0)
//             up = nums[i][j] + solve(i - 1, j, nums);

//         if (j > 0)
//             left = nums[i][j] + solve(i, j - 1, nums);

//         return min(up, left);
//   }
//   int minPathCost(vector<vector<int>> &nums) {
//     int n = nums.size();
//     int m = nums[0].size();
//     return solve(n-1, m-1, nums);
//   }
// };
class Solution {
public:
  int solve(int i, int j, vector<vector<int>> &nums, vector<vector<int>> &dp) {
    
  }
  int minPathCost(vector<vector<int>> &nums) {
    int n = nums.size();
    int m = nums[0].size();
    vector<vector<int>> dp(n, vector<int>(m, -1));

    return solve(n - 1, m - 1, nums, dp);
  }
};

int main() {
  vector<vector<int>> nums = {{10, 8, 2}, {10, 5, 100}, {1, 1, 2}};
  Solution s;
  int res = s.minPathCost(nums);
  cout << res << endl;
  return 0;
}