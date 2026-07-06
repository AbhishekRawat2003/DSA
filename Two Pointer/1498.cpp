// 1498. Number of Subsequences That Satisfy the Given Sum Condition

#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int mod = 1e9 + 7;
  int numSubseq(vector<int> &nums, int target) {
    int count = 0;
    int n = nums.size();
    sort(nums.begin(), nums.end());
    int left = 0;
    int right = n - 1;
    vector<int> power(n);
    power[0] = 1;
    for (int i = 1; i < n; i++) {
      power[i] = (2 * power[i - 1]) % mod;
    }
    while (left <= right) {
      if (nums[left] + nums[right] <= target) {
        count = (count + power[right - left]) % mod;
        left++;
      } else {
        right--;
      }
    }
    return count;
  }
};
int main() {
  vector<int> nums = {3, 5, 6, 7};
  int target = 9;

  Solution s;
  int result = s.numSubseq(nums, target);
  cout << result << endl;
  return 0;
}