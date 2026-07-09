#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
// => BRUTE FORCE O(N*Q)
  //   bool solve(vector<int> &queries, unordered_map<int, int> &mp, int
  //   maxDiff) {
  //     for (auto val : queries) {
  //       cout << "queries in solve: " << val << " ";
  //     }
  //     cout << endl;
  //     cout << "mp[queries[0]] - mp[queries[1]] = "
  //          << abs(mp[queries[0]] - mp[queries[1]]) << endl;
  //     int first = min(queries[0], queries[1]);
  //     int second = max(queries[0], queries[1]);
  //     for (int i = first; i < second; i++) {
  //       int diff = abs(mp[i] - mp[i + 1]);
  //       if (diff > maxDiff) {
  //         return false;
  //       }
  //     }
  //     return true;
  //   }
  //   vector<bool> pathExistenceQueries(int n, vector<int> &nums, int maxDiff,
  //                                     vector<vector<int>> &queries) {
  //     unordered_map<int, int> mp;
  //     vector<bool> res;
  //     for (int i = 0; i < nums.size(); i++) {
  //       mp[i] = nums[i];
  //     }
  //     for (int i = 0; i < queries.size(); i++) {
  //       res.push_back(solve(queries[i], mp, maxDiff));
  //     }
  //     return res;}

  // ==> OPTIMAL SOLUTION ARRAY + PREFIX SUM O(N+Q)
  vector<bool> pathExistenceQueries(int n, vector<int> nums, int maxDiff,
                                    vector<vector<int>> queries) {
    vector<int> prefix(n, 0);

    for (int i = 0; i < n - 1; i++) {

      int bad = abs(nums[i] - nums[i + 1]) > maxDiff ? 1 : 0;

      prefix[i + 1] = prefix[i] + bad;
    }

    vector<bool> ans;

    for (auto &q : queries) {

      int l = min(q[0], q[1]);
      int r = max(q[0], q[1]);

      if (prefix[r] - prefix[l] == 0)
        ans.push_back(true);
      else
        ans.push_back(false);
    }

    return ans;
  }
};

int main() {
  int n = 2;
  vector<int> nums = {2975, 50642};
  int maxDiff = 6;
  vector<vector<int>> queries = {{1, 0}};
  Solution s;
  vector<bool> res = s.pathExistenceQueries(n, nums, maxDiff, queries);
  for (auto val : res) {
    cout << val << " ";
  }
  cout << endl;
  return 0;
}