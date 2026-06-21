// 283. Move all zeroes to end

#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
  void moveZeroes(vector<int> &nums) {
    int left = 0;
    int right = 0;
    while (right < nums.size()) {
      if (nums[left] == 0 && left != right & nums[right] != 0) {
        swap(nums[left], nums[right]);
        left++;
      }
      else if(nums[left]!=0){
        left++;
      }
      right++;
    }
    for (auto num : nums) {
      cout << num << " ";
    }
    cout << endl;
  }
};
int main() {

  //   vector<int> nums = {0, 1, 0, 3, 12};
  vector<int> nums = {1, 0, 1};
  Solution s;
  s.moveZeroes(nums);
}