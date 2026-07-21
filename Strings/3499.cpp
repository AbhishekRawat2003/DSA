#include <iostream>
#include <string>
using namespace std;

class Solution
{
public:
    int maxActiveSectionsAfterTrade(string s)
    {
        int n = s.size();
        int maxSum = 0;
        int ones = 0;
        int prevRun = -1;
        int i = 0;
        while (i < n)
        {
            if (s[i] == '1')
            {
                ones++;
                i++;
            }
            else
            {
                int curSum = 0;
                while (i < n && s[i] == '0')
                {
                    curSum++;
                    i++;
                }
                if (prevRun > 0)
                {
                    maxSum = max(maxSum, prevRun + curSum);
                }
                prevRun = curSum;
            }
        }
        return ones + maxSum;
    }
};
int main()
{
    string str1 = "01";
    string str2 = "0100";
    string str3 = "1000100";
    string str4 = "01010";
    Solution s;

    cout << "1. " << s.maxActiveSectionsAfterTrade(str1) << endl;
    cout << "2. " << s.maxActiveSectionsAfterTrade(str2) << endl;
    cout << "3. " << s.maxActiveSectionsAfterTrade(str3) << endl;
    cout << "4. " << s.maxActiveSectionsAfterTrade(str4) << endl;
    return 0;
}