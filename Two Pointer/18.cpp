// 4 sum
#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

class Solution {
public:
  vector<vector<int>> fourSum(vector<int> &nums, int target) {
    vector<vector<int>> result;
    int n = nums.size();
    sort(nums.begin(), nums.end());
    for (int i = 0; i < n - 3; i++) {
      if (i > 0 && nums[i] == nums[i - 1])
        continue; // skip duplicates

      for (int j = i + 1; j < n - 2; j++) {
        if (j > i + 1 && nums[j] == nums[j - 1])
          continue; // skip duplicates

        int l = j + 1, r = n - 1;
        while (l < r) {
          long long sum = (long long)nums[i] + nums[j] + nums[l] + nums[r];

          if (sum == target) {
            result.push_back({nums[i], nums[j], nums[l], nums[r]});
            while (l < r && nums[l] == nums[l + 1])
              l++; // skip duplicates
            while (l < r && nums[r] == nums[r - 1])
              r--; // skip duplicates
            l++;
            r--;
          } else if (sum < target) {
            l++;
          } else {
            r--;
          }
        }
      }
    }
    return result;
  }
};

int main() {
  vector<int> nums = {1, 0, -1, 0, -2, 2};
  int target = 0;

  Solution s;
  vector<vector<int>> result = s.fourSum(nums, target);

  for (auto num : result) {
    for (auto val : num) {
      cout << val << " ";
    }
    cout << endl;
  }

  return 0;
}