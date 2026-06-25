// 3737. Count Subarrays With Majority Element I

#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
  bool check(vector<int> &arr, int target) {
    int count = 0;
    for (int x : arr) {
      if (x == target)
        count++;
    }

    return 2 * count > arr.size();
  }
  int countMajoritySubarrays(vector<int> &nums, int target) {

    int count = 0;
    for (int i = 0; i < nums.size(); i++) {
      vector<int> arr;
      for (int j = i; j < nums.size(); j++) {
        arr.push_back(nums[j]);
        if (check(arr, target)) {
          count++;
        }
      }
    }
    return count;
  }
};

int main() {
  vector<int> nums = {1, 2, 3};
  int target = 4;
  Solution s;
  int count = s.countMajoritySubarrays(nums, target);
  cout << "Possible No. of Subarrays are: " << count << endl;
  return 0;
}