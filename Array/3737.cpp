// 3737. Count Subarrays With Majority Element I

#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

// Brute force => O(n³) - O(n²) subarrays × O(n) check each time.
//  class Solution {
//  public:
//    bool check(vector<int> &arr, int target) {
//      int count = 0;
//      for (int x : arr) {
//        if (x == target)
//          count++;
//      }

//     return 2 * count > arr.size();
//   }
//   int countMajoritySubarrays(vector<int> &nums, int target) {

//     int count = 0;
//     for (int i = 0; i < nums.size(); i++) {
//       vector<int> arr;
//       for (int j = i; j < nums.size(); j++) {
//         arr.push_back(nums[j]);
//         if (check(arr, target)) {
//           count++;
//         }
//       }
//     }
//     return count;
//   }
// };
class Solution {
public:
  int countMajoritySubarrays(vector<int> nums, int target) {
    int n = nums.size();
    vector<int> prefix(n + 1, 0);

    for (int i = 0; i < n; i++) {
      prefix[i + 1] = prefix[i] + (nums[i] == target ? 1 : -1);
    }
    int count = 0;
    for (int i = 0; i < n; i++) {
      for (int j = i+1; j <= n; j++) {
        if (prefix[j] - prefix[i] > 0) {
          count++;
        }
      }
    }
    return count;
  }
};
int main() {
  vector<int> nums = {1, 2, 2, 3};
  int target = 2;
  Solution s;
  int count = s.countMajoritySubarrays(nums, target);
  cout << "Possible No. of Subarrays are: " << count << endl;
  return 0;
}