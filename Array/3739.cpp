#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
class Solution {
public:
  ll countMajoritySubarrays(vector<int> &nums, int target) {
    int n = nums.size();
    vector<ll> prefix(n + 1, 0);
    int count = 0;
    for (int i = 0; i < n; i++) {
      prefix[i + 1] = prefix[i] + (nums[i] == target ? 1 : -1);
    }

    for (int i = 0; i < n; i++) {
      for (int j = i; j < n; j++) {
        if (prefix[i - 1] < prefix[j]) {
          count++;
        }
      }
    }
    for (auto val : prefix) {
      cout << val << endl;
    }
    return count;
  }
};
int main() {
  vector<int> nums = {1, 2, 2, 3};
  int target = 2;
  Solution s;
  ll result = s.countMajoritySubarrays(nums, target);
  cout << result << endl;
  return 0;
}