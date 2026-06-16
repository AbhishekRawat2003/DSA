// 3612. Process String with Special Operations I

#include <iostream>
#include <string>
#include<algorithm>
using namespace std;
class Solution {
public:
  string processStr(string s) {
    string st;
    for (char c : s) {
      if (c >= 'a' && c <= 'z') {
        st.push_back(c);
      } else if (c == '*') {
        if (!st.empty())
          st.pop_back();
      } else if (c == '#') {
        st += st;
      } else if (c == '%') {
        reverse(st.begin(), st.end());
      }
    }

    return st;
  }
};
int main() {
  string str = "a#b%*";
  Solution s;
  string result = s.processStr(str);
  cout << result << endl;
  return 0;
}