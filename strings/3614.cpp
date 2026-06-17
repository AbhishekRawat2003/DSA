#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
  char processStr(string s, long long k) {
    long long len = 0;
    for (auto ch : s) {
      if (ch >= 'a' && ch <= 'z') {
        len++;
      } else if (ch == '*') {
        if (len > 0)
          len--;
      } else if (ch == '#') {
        len *= 2;
      }
      continue;
    }

    if (k >= len || k < 0)
      return '.';

    for (int i = (int)s.size() - 1; i >= 0; i--) {
      char c = s[i];
      if (c >= 'a' && c <= 'z') {
        if (k == len - 1) {
          return c;
        }
        len--;
      } else if (c == '#') {
        len /= 2;
        k %= len;
      } else if (c == '%') {
        k = len - 1 - k;
      } else if (c == '*') {
        len++;
      }
    }
    return '.';
  }
};
int main() {
  string str = "%edx#n#lkc####uom##qg#%#b#ek%##%%ocr#m%#fv%i%%#n#u%%#n#q%v#"
               "rwvd##t###%#%%%o*##r#gr*gz#dm%ez";
  //   string str = "a#b%*";
  int k = 4780;
  Solution s;
  char result = s.processStr(str, k);
  cout << result << endl;
  return 0;
}