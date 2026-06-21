// 167. Two Sum II - Input Array Is Sorted

#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
  vector<int> twoSum(vector<int> &numbers, int target) {
    int left = 0;
    int right = numbers.size() - 1;
    while (left < right) {
      int sum = numbers[left] + numbers[right];
      if (sum == target) {
        return {left + 1, right + 1};
      } else if (sum > target) {
        right--;
      } else {
        left++;
      }
    }

    return {};
  }
};

int main() {
  vector<int> numbers = {2, 7, 11, 15};
  int target = 13;
  Solution s;
  vector<int> result = s.twoSum(numbers, target);
  for (auto num : result) {
    cout << num << " ";
  }
  cout << endl;
  return 0;
}