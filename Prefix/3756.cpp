#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
  // Brute force gives TLE so we use Prefix Sum for optimal Solution.
  long long mod = 1e9 + 7;

  //   int solve(int l, int r, string &s) {
  //     long long sum = 0;
  //     long long mul = 0;

  //     for (int i = l; i <= r; i++) {
  //       int num = s[i] - '0';

  //       if (num != 0) {
  //         sum += num;
  //         mul = (mul * 10 + num)%mod;
  //       }
  //     }

  //     return (sum * mul) % mod;
  //   }
  //   vector<int> sumAndMultiply(string s, vector<vector<int>> &queries) {
  //     vector<int> res;
  //     for (int i = 0; i < queries.size(); i++) {
  //       res.push_back(solve(queries[i][0], queries[i][1], s));
  //     }

  //     return res;
  //   }

  // prefix
  vector<int> sumAndMultiply(string &s, vector<vector<int>> &queries) {
    int n = s.size();
    vector<long long> concatination(n + 1, 0);
    vector<int> preSum(n + 1, 0);
    vector<long long> power(n + 1, 1);
    vector<long long> digitSum(n + 1, 0);

    for (int i = 1; i <= n; i++)
      power[i] = (power[i - 1] * 10) % mod;

    for (int i = 1; i <= n; i++) {
      int num = s[i - 1] - '0';
      if (num != 0) {
        concatination[i] = (concatination[i - 1] * 10 + num) % mod;
        preSum[i] = preSum[i - 1] + 1;
        digitSum[i] = digitSum[i - 1] + num;
      } else {
        concatination[i] = concatination[i - 1];
        preSum[i] = preSum[i - 1];
        digitSum[i] = digitSum[i - 1];
      }
    }

    vector<int> res;
    res.reserve(queries.size());
    for (auto &q : queries) {
      int l = q[0], r = q[1];

      long long sum = ((digitSum[r + 1] - digitSum[l]) % mod + mod) % mod;

      int cnt = preSum[r + 1] - preSum[l];
      long long mul =
          ((concatination[r + 1] - concatination[l] * power[cnt]) % mod + mod) %
          mod;

      res.push_back((int)((sum * mul) % mod));
    }
    return res;
  }
};
int main() {
  string str = "9876543210";
  vector<vector<int>> queries = {{0, 9}};
  Solution s;
  vector<int> res = s.sumAndMultiply(str, queries);
  for (auto val : res) {
    cout << val << " " << endl;
  }
  return 0;
}