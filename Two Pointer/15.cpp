// 3Sum

#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
using namespace std;
class Solution {
public:
  vector<vector<int>> threeSum(vector<int> &nums) {
    sort(nums.begin(), nums.end());

    set<vector<int>> uniqueTriplets;
    int n = nums.size();

    for (int pivot = 0; pivot < n - 2; pivot++) {
      int left = pivot + 1;
      int right = n - 1;

      while (left < right) {
        int sum = nums[pivot] + nums[left] + nums[right];

        if (sum == 0) {
          uniqueTriplets.insert({nums[pivot], nums[left], nums[right]});
          left++;
          right--;
        } else if (sum < 0) {
          left++;
        } else {
          right--;
        }
      }
    }

    return vector<vector<int>>(uniqueTriplets.begin(), uniqueTriplets.end());
  }
};

int main() {
  vector<int> nums = {-1, 0, 1, 2, -1, -4};

  Solution s;
  vector<vector<int>> result = s.threeSum(nums);

  for (const auto &vec : result) {
    for (int x : vec) {
      cout << x << " ";
    }
    cout << endl;
  }

  return 0;
}
// brute force
// set<vector<int>> uniqueTriplets;

// for (int i = 0; i < nums.size(); i++) {
//   for (int j = i + 1; j < nums.size(); j++) {
//     for (int k = j + 1; k < nums.size(); k++) {

//       if (nums[i] + nums[j] + nums[k] == 0) {

//         vector<int> triplet = {nums[i], nums[j], nums[k]};

//         sort(triplet.begin(), triplet.end());

//         uniqueTriplets.insert(triplet);
//       }
//     }
//   }
// }

// for (auto triplet : uniqueTriplets) {
//   for (int num : triplet) {
//     cout << num << " ";
//   }
//   cout << endl;
// }
