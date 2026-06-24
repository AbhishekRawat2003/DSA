// Frog Jump
#include <bits/stdc++.h>
#include <cstring>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;
// recursive approach
// class Solution {
// public:
//   bool solve(int idx, int jump, vector<int> &stones) {
//     int n = stones.size();
//     if (idx == n - 1)
//       return true;
//     for (int nextJump = jump - 1; nextJump <= jump + 1; nextJump++) {
//       if (nextJump <= 0)
//         continue;
//       int target = stones[idx] + nextJump;
//       for (int j = idx + 1; j < n; j++) {
//         if (stones[j] == target) {
//           if (solve(j, nextJump, stones))
//             return true;
//         }
//         if (stones[j] > target)
//           break;
//       }
//     }
//     return false;
//   }
//   bool canCross(vector<int> &stones) {
//     if (stones[1] != 1)
//       return false;

//     return solve(1, 1, stones);
//   }
// };

//=============================Memoization===============================
// class Solution {
// public:
//   unordered_map<int, int> pos;
//   map<pair<int, int>, bool> dp;

//   bool solve(int idx, int jump, vector<int> &stones) {
//     if (idx == stones.size() - 1)
//       return true;

//     if (dp.count({idx, jump}))
//       return dp[{idx, jump}];

//     for (int nj = jump - 1; nj <= jump + 1; nj++) {
//       if (nj <= 0)
//         continue;

//       int nextStone = stones[idx] + nj;

//       if (pos.count(nextStone) && solve(pos[nextStone], nj, stones))
//         return dp[{idx, jump}] = true;
//     }

//     return dp[{idx, jump}] = false;
//   }

//   bool canCross(vector<int> &stones) {
//     if (stones.size() < 2 || stones[1] != 1)
//       return false;

//     for (int i = 0; i < stones.size(); i++)
//       pos[stones[i]] = i;

//     return solve(1, 1, stones);
//   }
// };

//==================Tabulation=======================
class Solution {
public:
  bool canCross(vector<int> &stones) {
    int n = stones.size();
    if (stones[1] != 1) {
      return false;
    }
    unordered_map<int, int> mp;
    // for (auto val : stones) { //  mp stores value→count (frequency), not
    // value→index
    //   mp[val]++;
    // }
    for (int i = 0; i < n; i++) {
      mp[stones[i]] = i;
    }

    vector<unordered_set<int>> dp(n);
    dp[1].insert(1);

    for (int i = 0; i < n; i++) {
      for (int jump : dp[i]) {
        for (int nj = jump - 1; nj <= jump + 1; nj++) {
          if (mp.count(stones[i] + nj)) {
            int nextIdx = mp[stones[i] + nj];
            dp[nextIdx].insert(nj);
          }
        }
      }
    }
    return !dp[n - 1].empty();
  }
};
int main() {
  vector<int> stones = {0, 1, 3, 5, 6, 8, 12, 17};
  Solution s;
  // Solution s;
  bool res = s.canCross(stones);
  cout << res << endl;
  return 0;
}