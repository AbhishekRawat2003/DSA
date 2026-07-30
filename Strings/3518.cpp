#include <bits/stdc++.h>
using namespace std;
struct TestCase
class Solution {
public:
    string smallestPalindrome(string s, int k) {
        int n = s.size();
        vector<long long> freq(26, 0);
        for (char ch : s)
            freq[ch - 'a']++;

        vector<long long> halfCnt(26);
        for (int i = 0; i < 26; i++)
            halfCnt[i] = freq[i] / 2;

        int halfLen = n / 2;
        int midChar = -1;
        if (n % 2 == 1) {
            for (int i = 0; i < 26; i++) {
                if (freq[i] % 2 == 1) {
                    midChar = i;
                    break;
                }
            }
        }

        const long long BOUND = k;
        auto permCount = [&](vector<long long>& cnt,
                             long long remaining) -> long long {
            long long result = 1;
            long long nrem = remaining;
            for (int i = 0; i < 26; i++) {
                long long c = cnt[i];
                if (c == 0)
                    continue;
                long long kk = min(c, nrem - c);
                long long cur = 1;
                for (long long j = 1; j <= kk; j++) {

                    cur = cur * (nrem - kk + j) / j;
                    if (cur > BOUND)
                        break;
                }
                if (cur > BOUND)
                    return BOUND + 1;

                if (result > (BOUND + 1) / max(cur, 1LL) + 1) {
                    return BOUND + 1;
                }
                result *= cur;
                if (result > BOUND)
                    return BOUND + 1;
                nrem -= c;
            }
            return result;
        };

        long long total = permCount(halfCnt, halfLen);
        if (total < k)
            return "";

        vector<long long> cnt = halfCnt;
        long long remaining = halfLen;
        long long remK = k;
        string half;
        half.reserve(halfLen);

        for (int pos = 0; pos < halfLen; pos++) {
            for (int c = 0; c < 26; c++) {
                if (cnt[c] == 0)
                    continue;
                cnt[c]--;
                long long cval = permCount(cnt, remaining - 1);
                if (remK <= cval) {
                    half.push_back('a' + c);
                    remaining--;
                    break;
                } else {
                    remK -= cval;
                    cnt[c]++;
                }
            }
        }

        string rev(half.rbegin(), half.rend());
        if (n % 2 == 1) {
            return half + string(1, 'a' + midChar) + rev;
        }
        return half + rev;
    }
};
int main()
{
    Solution sol;

    vector<TestCase> tests = {
        {"a", 1, "a"},
        {"a", 2, ""},

        {"aa", 1, "aa"},
        {"aa", 2, ""},

        {"aba", 1, "aba"},
        {"aba", 2, ""},

        {"abba", 1, "abba"},
        {"abba", 2, "baab"},
        {"abba", 3, ""},

        {"acca", 1, "acca"},
        {"acca", 2, "caac"},
        {"acca", 3, ""},

        {"baab", 1, "abba"},
        {"baab", 2, "baab"},
        {"baab", 3, ""},

        {"deffed", 1, "deffed"},
        {"deffed", 2, "efddfe"},
        {"deffed", 3, ""},

        {"aaaabaaaa", 1, "aaaabaaaa"},
        {"aaaabaaaa", 2, ""},

        {"zzzz", 1, "zzzz"},
        {"zzzz", 2, ""},

        {"zzzzzz", 1, "zzzzzz"},
        {"zzzzzz", 2, ""},

        {"aaaaaaaa", 1, "aaaaaaaa"},
        {"aaaaaaaa", 2, ""},

        {"abcxcba", 1, "abcxcba"},
        {"abcxcba", 2, "acbxbca"},
        {"abcxcba", 3, "bacxcab"},
        {"abcxcba", 4, "bcaxacb"},
        {"abcxcba", 5, "cabxbac"},
        {"abcxcba", 6, "cbaxabc"},
        {"abcxcba", 7, ""},

        {"abcdcba", 1, "abcdcba"},
        {"abcdcba", 2, "abdcdba"},
        {"abcdcba", 3, "acbdbca"},
        {"abcdcba", 4, "acdbdca"},
        {"abcdcba", 5, "adbcbda"},
        {"abcdcba", 6, "adcbcda"},
        {"abcdcba", 7, ""},

        {"abcddcba", 1, "abcddcba"},
        {"abcddcba", 24, "dcbaabcd"},
        {"abcddcba", 25, ""},

        {"abcdeedcba", 1, "abcdeedcba"},
        {"abcdeedcba", 120, "edcbaabcde"},
        {"abcdeedcba", 121, ""},

        {"aaaaaaaaaaaaaaaa", 1, "aaaaaaaaaaaaaaaa"},
        {"aaaaaaaaaaaaaaaa", 100, ""},
    };
    for (auto &t : tests)
    {

        string ans = sol.smallestPalindrome(t.s, t.k);

        cout << "Input    : " << t.s << "  " << t.k << endl;
        cout << "Expected : " << t.expected << endl;
        cout << "Your Ans : " << ans << endl;

        if (ans == t.expected)
            cout << "✅ PASS\n";
        else
            cout << "❌ FAIL\n";

        cout << "-------------------------\n";
    }
    return 0;
}