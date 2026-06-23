// Frog Jump
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  // recursive approach
  bool solve(int idx, int jump, vector<int> &stones) {
    int n = stones.size();
    if (idx == n - 1)
      return true;
    for (int nextJump = jump - 1; nextJump <= jump + 1; nextJump++) {

      if (nextJump <= 0)
        continue;

      int target = stones[idx] + nextJump;

      for (int j = idx + 1; j < n; j++) {

        if (stones[j] == target) {
          if (solve(j, nextJump, stones))
            return true;
        }

        if (stones[j] > target)
          break;
      }
    }

    return false;
  }
  bool canCross(vector<int> &stones) {
    if (stones[1] != 1)
      return false;

    return solve(1, 1, stones);
  }
};
int main() {
  vector<int> stones = {0, 1, 3, 5, 6, 8, 12, 17};
  Solution s;
  bool res = s.canCross(stones);
  cout << res << endl;
  return 0;
}