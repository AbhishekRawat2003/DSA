#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;
class Solution {
public:
  int maxNumberOfBalloons(string text) {
    unordered_map<char, int> freq = {
        {'b', 0}, {'a', 0}, {'l', 0}, {'o', 0}, {'n', 0}};

    for (char ch : text) {
      if (freq.find(ch) != freq.end()) {
        freq[ch]++;
      }
    }

    int ans =
        min({freq['b'], freq['a'], freq['n'], freq['l'] / 2, freq['o'] / 2});
    return ans;
  }
};
int main() {
  string text = "loonbalxballpoon";
  Solution s;
  int result = s.maxNumberOfBalloons(text);
  cout << result << endl;

  return 0;
}