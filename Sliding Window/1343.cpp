// 1343. Number of Sub-arrays of Size K and Average Greater than or Equal to
// Threshold

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  bool isValidWindow(int sum, int k, int threshold) {
    if ((int)sum >= k * threshold) {
      return 1; // true
    }
    return 0; // false
  }

  int numOfSubarrays(vector<int> &arr, int k, int threshold) {
    int count = 0;
    int sum = 0;
    for (int i = 0; i < k; i++) {
      sum += arr[i];
    }
    if (isValidWindow(sum, k, threshold))
      count++;
    for (int i = k; i < arr.size(); i++) {
      sum = sum - arr[i - k] + arr[i];
      if (isValidWindow(sum, k, threshold)) {
        count++;
      }
    }
    return count;
  }
};
int main() {
  vector<int> nums = {2, 2, 2, 2, 5, 5, 5, 8};
  int k = 3;
  int threshold = 4;
  Solution s;
  int result = s.numOfSubarrays(nums, k, threshold);
  cout << " No. of SubArrays: " << result << endl;
  return 0;
}