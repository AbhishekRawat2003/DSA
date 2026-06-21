// 904. Fruit Into Basket
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
  int totalFruit(vector<int> &fruits) {
    int left = 0;
    int ans = 0;
    unordered_map<int, int> freq;

    for (int right = 0; right < fruits.size(); right++) {
      freq[fruits[right]]++;

      while (freq.size() > 2) {
        freq[fruits[left]]--;

        if (freq[fruits[left]] == 0) {
          freq.erase(fruits[left]);
        }

        left++;
      }

      ans = max(ans, right - left + 1);
    }

    return ans;
  }
};

int main() {
  vector<int> fruits = {3, 3, 3, 1, 2, 1, 1, 2, 3, 3, 4};

  Solution s;
  int result = s.totalFruit(fruits);

  cout << "the maximum number of fruits: " << result << endl;

  return 0;
}