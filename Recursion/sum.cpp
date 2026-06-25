#include <iostream>
#include <vector>
using namespace std;

// recursion => DP
int sumN(int n, vector<int> dp) {
  if (n == 0) {
    return 0;
  }
  if (dp[n] != -1) {
    return dp[n];
  }
  return dp[n] = n + sumN(n - 1, dp);
}
int main() {
  int n = 10;
  vector<int> dp(n + 1, -1);
  int res = sumN(n, dp);
  cout << res << endl;
  return 0;
}
