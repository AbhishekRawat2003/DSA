#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
#include <algorithm>

class Solution
{
public:
    string smallestPalindrome(string s)
    {
        // int n = s.length();
        // int mid = n / 2;
        // sort(begin(s), begin(s) + mid);
        // for (int i = 0; i < mid; i++)
        // {
        //     s[n - 1 - i] = s[i];
        // }
        // return s;

        vector<int> freq(26, 0);

        for (char c : s)
        {
            freq[c - 'a']++;
        }
        string left = "";
        char mid = '\0';
        for (int i = 0; i < 26; i++)
        {
            left.append(freq[i] / 2, char('a' + i));
            if (freq[i] % 2)
            {
                mid = char('a' + i);
            }
        }
        string right = left;
        reverse(right.begin(), right.end());
        if (mid != '\0')
        {
            return left + mid + right;
        }
        return left + right;
    }
};
int main()
{
    string str = "acddca";
    Solution s;
    cout << s.smallestPalindrome(str) << endl;
    return 0;
}