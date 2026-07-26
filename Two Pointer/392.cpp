#include <iostream>
#include <string>
#include <vector>
using namespace std;

#include <iostream>
#include <string>
using namespace std;

class Solution
{
public:
    bool isSubsequence(string s, string t)
    {
        if (s.size() > t.size())
            return false;

        int i = 0;
        int j = 0;

        while (i < s.size() && j < t.size())
        {
            if (s[i] == t[j])
            {
                i++;
            }

            j++;
        }

        return i == s.size();
    }
};
int main()
{
    string s = "axc";
    string t = "ahbgdc";
    Solution sol;
    cout << sol.isSubsequence(s, t) << endl;
    return 0;
}