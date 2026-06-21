// 3. Longest Substring Without Repeating Characters

#include <iostream>
using namespace std;
#include <string>
#include <unordered_set>

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int len = 0;
        int maxLen = 0;
        unordered_set<char> mp;

        for (int i = 0; i < s.length(); i++)
        {
            while (mp.count(s[i]))
            {
                mp.erase(s[len++]);
            }
            mp.insert(s[i]);
            maxLen = max(maxLen, i - len + 1);
        }
        return maxLen;
    }
};

int main()
{
    string s = "abcabcbb";
    Solution sol;
    int result = sol.lengthOfLongestSubstring(s);
    cout << "lenght of Longest Substring: " << result << endl;

    return 0;
}