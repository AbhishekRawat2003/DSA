// 76. Minimum Window Substring

#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;
#include <climits>
class Solution
{
public:
    string minWindow(string s, string t)
    {
        if (s.length() < t.length())
            return "";
        unordered_map<char, int> required;
        for (auto ch : t)
        {
            required[ch]++;
        }
        unordered_map<char, int> window;
        int formed = 0;
        int need = required.size();
        int l = 0;
        int minLen = INT_MAX;
        int minStart = 0;

        for (int r = 0; r < s.length(); r++)
        {
            window[s[r]]++;

            if (required.count(s[r]) && window[s[r]] == required[s[r]])
            {
                formed++;
            }
            while (formed == need)
            {
                if (r - l + 1 < minLen)
                {
                    minLen = r - l + 1;
                    minStart = l;
                }

                window[s[l]]--;
                if (required.count(s[l]) && window[s[l]] < required[s[l]])
                {
                    formed--;
                }
                l++;
            }
        }
        return minLen == INT_MAX ? "" : s.substr(minStart, minLen);
    }
};

int main()
{
    string s = "ADOBECODEBANC";
    string t = "ABC";
    Solution sol;
    string result = sol.minWindow(s, t);
    cout << "Result: " << result << endl;

    return 0;
}