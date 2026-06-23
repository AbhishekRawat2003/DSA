#include <iostream>
#include <vector>
using namespace std;
int fibo(int n, vector<int> &dp) {
  if (n <= 1) {
    return n;
  }
  if (dp[n] != -1)
    return dp[n];
  return dp[n] = fibo(n - 1, dp) + fibo(n - 2, dp);
}
int main() {
  int n = 10;
  vector<int> dp(n + 1, -1);
  int result = fibo(n, dp);
  cout << result;
  cout << endl;
  return 0;
}


// step to create: recursive-> DP.
// step 0=> declare dp array with value -1;
// step 1=> store value in dp[n] if dp[n] == -1;
// step 2=> check if dp present then resturn else store again into dp array.