// Maximum Ice Cream Bars
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int maxIceCream(vector<int> &costs, int coins) {
    int maximum = 0;
    sort(costs.begin(), costs.end());

    for (int i = 0; i < costs.size(); i++) {
      if (coins >= costs[i]) {
        maximum++;
        coins -= costs[i];
      }
    }
    return maximum;
  }
};

int main() {
  //   vector<int> costs = {1, 3, 2, 4, 1};
  //   int coins = 7;

  vector<int> costs = {10, 6, 8, 7, 7, 8};
  int coins = 5;

  Solution s;
  int result = s.maxIceCream(costs, coins);
  cout << "Max Ice Cream are: " << result << endl;
  return 0;
}