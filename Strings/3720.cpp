#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
    string lexGreaterPermutation(string s, string target)
    {
        vector<int> count(26, 0);

        for (char ch : s)
        {
            count[ch - 'a']++;
        }

        string ans = "";

        for (int i = 0; i < s.size(); i++)
        {
            char c = target[i];

            if (count[c - 'a'] > 0)
            {
                ans.push_back(c);
                count[c - 'a']--;
            }
            else
            {
                bool found = false;

                for (int j = (c - 'a') + 1; j < 26; j++)
                {
                    if (count[j] > 0)
                    {
                        ans.push_back('a' + j);
                        count[j]--;

                        for (int k = 0; k < 26; k++)
                        {
                            while (count[k] > 0)
                            {
                                ans.push_back('a' + k);
                                count[k]--;
                            }
                        }

                        return ans;
                    }
                }

                if (!found)
                {
                    break;
                }
            }
        }

        for (int i = ans.size() - 1; i >= 0; i--)
        {
            count[ans[i] - 'a']++;

            for (int j = (target[i] - 'a') + 1; j < 26; j++)
            {
                if (count[j] > 0)
                {
                    ans.resize(i);

                    ans.push_back('a' + j);
                    count[j]--;

                    for (int k = 0; k < 26; k++)
                    {
                        while (count[k] > 0)
                        {
                            ans.push_back('a' + k);
                            count[k]--;
                        }
                    }

                    return ans;
                }
            }
        }

        return "";
    }
};

int main()
{
    string str = "aab";
    string target = "abb";

    Solution s;
    cout << s.lexGreaterPermutation(str, target) << endl;

    return 0;
}