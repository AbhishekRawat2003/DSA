#include <iostream>
#include <string>
#include <climits>
using namespace std;

class Solution
{
public:
    string shortestBeautifulSubstring(string s, int k)
    {
        int left = 0;
        int countOnes = 0;
        string ans = "";

        for (int right = 0; right < s.size(); right++)
        {
            if (s[right] == '1')
            {
                countOnes++;
            }

            while (countOnes == k)
            {
                string curr = s.substr(left, right - left + 1);

                if (ans == "" || curr.length() < ans.length() ||
                    (curr.length() == ans.length() && curr < ans))
                {
                    ans = curr;
                }

                if (s[left] == '1')
                {
                    countOnes--;
                }

                left++;
            }
        }

        return ans;
    }
};

int main()
{
    string str = "100011001";
    int k = 3;

    Solution s;
    cout << s.shortestBeautifulSubstring(str, k);

    return 0;
}