#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;

ll powerN(int n, int power, vector<ll> &dp) {
  if (power == 0)
    return 1;

  if (dp[power] != -1)
    return dp[power];

  return dp[power] = n * powerN(n, power - 1, dp);
}
int main() {
  int n = 2;
  int power = 40;

  vector<ll> dp(power + 1, -1);

  ll res = powerN(n, power, dp);

  cout << "RESULT: " << res << endl;
  return 0;
}