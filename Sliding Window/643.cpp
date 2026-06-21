// Maximum Average Subarray I

// if (nums.size() == k) {
//   double sum = 0;
//   for (auto num : nums) {
//     sum += num;
//   }

//   return sum / k;
// }
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  double findMaxAverage(vector<double> &nums, int k) {

    if (nums.size() == k) {
      double sum = 0;
      for (auto num : nums) {
        sum += num;
      }
      return sum / k;
    }
    double sum = 0;

    // First window
    for (int i = 0; i < k; i++) {
      sum += nums[i];
    }

    double maxSum = sum;

    // Slide window
    for (int i = k; i < nums.size(); i++) {
      sum += nums[i] - nums[i - k];
      maxSum = max(maxSum, sum);
    }

    return maxSum / k;
  }
};

int main() {
  vector<double> nums = {1, 12, -5, -6, 50, 3};
  int k = 6;

  Solution s;
  double result = s.findMaxAverage(nums, k);

  cout << "==========" << endl;
  cout << result << endl;

  return 0;
}