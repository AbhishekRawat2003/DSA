// 1358. Number of Substrings Containing All Three Characters

#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;
class Solution {
public:
  int numberOfSubstrings(string s) {
    unordered_map<char, int> freq;
    int left = 0;
    int nos = 0;
    // Expand
    for (int right = 0; right < s.size(); right++) {
      freq[s[right]]++;
      while (freq['a'] > 0 && freq['b'] > 0 && freq['c'] > 0) {
        nos += s.size() - right;
        freq[s[left]]--;
        left++;
      }
    }
    return nos;
  }
};
int main() {
//   string str = "aaacb";
    string str = "abcabc";
  Solution s;
  int result = s.numberOfSubstrings(str);
  cout << result << endl;
  return 0;
}