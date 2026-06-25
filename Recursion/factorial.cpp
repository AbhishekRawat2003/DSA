#include <iostream>
#include <vector>
using namespace std;
// Recursion -> Dp
int factorial(int n, vector<int> &dp) {
  if (n <= 1)
    return 1;
  if (dp[n] != -1) {
    return dp[n];
  }
  return dp[n] = n * factorial(n - 1, dp);
}
int main() {
  int n = 5;
  vector<int> dp(n + 1, -1);

  int res = factorial(n, dp);
  cout << "res: " << res << endl;
  for (auto val : dp) {
    cout << val << " ";
  }
  cout << endl;
  return 0;
}