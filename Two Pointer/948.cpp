// Bag of Tokens
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
  int bagOfTokensScore(vector<int> &tokens, int power) {
    sort(tokens.begin(), tokens.end());
    int left = 0;
    int right = tokens.size() - 1;
    cout << "Array size: " << right << endl;
    int score = 0;
    int currentScore = 0;
    int ans = 0;
    while (left <= right) {
      if (tokens[left] <= power) { // play
        // face-up
        power -= tokens[left++];
        score++;
        currentScore = max(currentScore, score);
      } else if (currentScore >= 1) { // paly face-down
        power += tokens[right--];
        score--;
      } else {
        break;
      }
    }
    return currentScore;
  }
};
int main() {
  vector<int> tokens = {200, 100};
  int power = 150;
  Solution s;
  int result = s.bagOfTokensScore(tokens, power);
  cout << result << endl;
  return 0;
}