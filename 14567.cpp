// 1456. Maximum Number of Vowels in a Substring of Given Length

#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;
class Solution {
public:
  int maxVowels(string s, int k) {
    int sw = 0;
    unordered_set<char> vowel = {'a', 'e', 'i', 'o', 'u'};
    for (int i = 0; i < k; i++) {
      if (vowel.count(s[i])) {
        sw++;
      }
    }
    int maxVowel = sw;
    for (int i = k; i < s.size(); i++) {

    if (vowel.count(s[i - k])) {
        sw--;
    }

    if (vowel.count(s[i])) {
        sw++;
    }

    maxVowel = max(maxVowel, sw);
}


    return maxVowel;
  }
};
int main() {
  string str = "abciiidef";
  int k = 3;
  Solution s;
  int res = s.maxVowels(str, k);
  cout << "Longest Vowel string is : " << res << endl;
  return 0;
}