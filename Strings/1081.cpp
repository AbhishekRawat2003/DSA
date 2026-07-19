#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
    string smallestSubsequences(string s)
    {
        vector<int> freq(26);
        vector<bool> visited(26, false);
        string str;
        for (char c : s)
        {
            freq[c - 'a']++;
        }
        for (char c : s)
        {
            freq[c - 'a']--;

            // visited
            if (visited[c - 'a'])
                continue;

            while (!str.empty() && str.back() > c && freq[str.back() - 'a'] > 0)
            {
                visited[str.back() - 'a'] = false;
                str.pop_back();
            }
            str.push_back(c);
            visited[c - 'a'] = true;
        }

        return str;
    }
};
int main()
{

    string str = "cbacdcbc";
    Solution s;
    cout << s.smallestSubsequences(str);
    return 0;
}