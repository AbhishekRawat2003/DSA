#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// class Solution
// {
// public:
//     string reverseWords(string s)
//     {
//         vector<string> ans;
//         string temp = "";

//         for (char c : s)
//         {
//             if (c != ' ')
//             {
//                 temp += c;
//             }
//             else
//             {
//                 if (!temp.empty())
//                 {
//                     ans.push_back(temp);
//                     temp = "";
//                 }
//             }
//         }

//         if (!temp.empty())
//             ans.push_back(temp);

//         reverse(ans.begin(), ans.end());

//         string res = "";

//         for (int i = 0; i < ans.size(); i++)
//         {
//             res += ans[i];

//             if (i != ans.size() - 1)
//                 res += " ";
//         }

//         return res;
//     }
// };

class Solution
{
public:
    string reverseWords(string s)
    {
        string str = "";
        int i = 0;
        int n = s.size();

        while (i < n)
        {

            while (i < n && s[i] == ' ')
                i++;

            while (i < n && s[i] != ' ')
            {
                str += s[i];
                i++;
            }

            while (i < n && s[i] == ' ')
                i++;

            if (i < n)
                str += ' ';
        }

        reverse(str.begin(), str.end());

        int start = 0;

        for (int end = 0; end <= str.size(); end++)
        {

            if (end == str.size() || str[end] == ' ')
            {

                reverse(str.begin() + start,
                        str.begin() + end);

                start = end + 1;
            }
        }

        return str;
    }
};
int main()
{
    string str = "the sky is blue";

    Solution s;

    cout << s.reverseWords(str) << endl;

    return 0;
}