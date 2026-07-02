#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

class Solution {
public:
  string reverseVowels(string s) {
    unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u',
                                  'A', 'E', 'I', 'O', 'U'};

    int left = 0;
    int right = s.size() - 1;

    while (left < right) {
      if (!vowels.count(s[left])) {
        left++;
      } else if (!vowels.count(s[right])) {
        right--;
      } else {
        swap(s[left], s[right]);
        left++;
        right--;
      }
    }

    return s;
  }
};

int main() {
  string str = "leetcode";

  Solution s;
  cout << s.reverseVowels(str) << endl;

  return 0;
}