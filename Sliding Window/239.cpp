// 239. Sliding Window Maximum
// priority queue and sliding window
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
  vector<int> maxSlidingWindow(vector<int> &nums, int k) {
    // int left = 0;
    // int right = k;
    // vector<int> ans;
    // while (left <= (nums.size() - k)) {
    //   int com = INT_MIN;
    //   for (int i = left; i < right; i++) {
    //     com = max(com, nums[i]);
    //   }
    //   ans.push_back(com);
    //   left++;
    //   right++;
    // }
    // return ans;

    deque<int> dq;
    vector<int> ans;

    for (int right = 0; right < nums.size(); right++) {
      while (!dq.empty() && nums[dq.back()] <= nums[right]) {
        dq.pop_back();
      }
      dq.push_back(right);

      if (dq.front() < right - k + 1) {
        dq.pop_front();
      }
      if (right >= k - 1) {
        ans.push_back(nums[dq.front()]); // front = max
      }
    }

    return ans;
  }
};

int main() {
  vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
  int k = 3;
  Solution s;
  vector<int> result = s.maxSlidingWindow(nums, k);
  for (auto num : result) {
    cout << num << " ";
  }

  return 0;
}
