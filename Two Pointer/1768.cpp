#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
  string mergeAlternately(string word1, string word2) {
    string ans = "";
    int i = 0;
    while (i < word1.size() && i < word2.size()) {
      ans.push_back(word1[i]);
      ans.push_back(word2[i]);
      i++;
    }
    while (i < word1.size()) {
      ans.push_back(word1[i++]);
    }
    while (i < word2.size()) {
      ans.push_back(word2[i++]);
    }

    return ans;
  }
};

int main() {
  string word1 = "abcd";
  string word2 = "pq";
  Solution s;
  string result = s.mergeAlternately(word1, word2);
  cout << result << endl;
  return 0;
}