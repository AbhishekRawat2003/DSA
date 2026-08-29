// #include <iostream>
// #include <string>
// #include <vector>
// #include <algorithm>
// using namespace std;

// class Solution
// {
// public:
//     bool solve(string &curr, vector<int> &count, string &target,
//                int i, bool greater, char midChar, int leftLen) //left=curr
//     {
//         if (i == leftLen)
//         {
//             string right = curr;
//             reverse(right.begin(), right.end());

//             string palindrome;

//             if (midChar != '\0')
//             {
//                 palindrome = curr + midChar + right;
//             }
//             else
//             {
//                 palindrome = curr + right;
//             }

//             return palindrome > target;
//         }


//         for (int ch = 0; ch < 26; ch++)
//         {
//             if (count[ch] == 0)
//                 continue;

//             curr.push_back('a' + ch);
//             count[ch]--;

//             if (solve(curr, count, target, i + 1, greater, midChar, leftLen))
//             {
//                 return true;
//             }


//             count[ch]++;
//             curr.pop_back();
//         }

//         return false;
//     }

//     string lexPalindromicPermutation(string s, string target)
//     {
//         int n = s.size();

//         vector<int> count(26, 0);
//         char midChar = '\0';


//         for (char &ch : s)
//         {
//             count[ch - 'a']++;
//         }


//         int oddCounts = 0;

//         for (int i = 0; i < 26; i++)
//         {
//             if (count[i] % 2 != 0)
//             {
//                 oddCounts++;
//                 midChar = 'a' + i;
//             }
//         }


//         if (oddCounts > 1)
//         {
//             return "";
//         }

//         for (int i = 0; i < 26; i++)
//         {
//             count[i] /= 2;
//         }

//         int leftLen = n / 2;
//         string left = "";

//         if (!solve(left, count, target, 0, false, midChar, leftLen))
//         {
//             return "";
//         }


//         string right = left;
//         reverse(right.begin(), right.end());

//         if (midChar != '\0')
//         {
//             return left + midChar + right;
//         }

//         return left + right;
//     }
// };

// int main()
// {
//     string str = "baba";
//     string target = "abba";

//     Solution obj;

//     cout << obj.lexPalindromicPermutation(str, target) << endl;

//     return 0;
// }




// TWO POINTER
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    string lexPalindromicPermutation(string s, string target)
    {
        int n = s.size();
        int leftLen = n / 2;

        vector<int> count(26, 0);

        // Count frequency
        for (char ch : s)
        {
            count[ch - 'a']++;
        }

        // Find middle character
        int oddCount = 0;
        char midChar = '\0';

        for (int i = 0; i < 26; i++)
        {
            if (count[i] % 2 == 1)
            {
                oddCount++;
                midChar = 'a' + i;
            }

            // Only half is needed for the left side
            count[i] /= 2;
        }

        if (oddCount > 1)
        {
            return "";
        }

        string left = "";

        // Step 1: Try to match target's left half
        int i = 0;

        while (i < leftLen)
        {
            int ch = target[i] - 'a';

            if (count[ch] == 0)
                break;

            left.push_back(target[i]);
            count[ch]--;

            i++;
        }

        // Case 1: Entire left half matched
        if (i == leftLen)
        {
            string right = left;
            reverse(right.begin(), right.end());

            string palindrome;

            if (midChar != '\0')
                palindrome = left + midChar + right;
            else
                palindrome = left + right;

            // Strictly greater
            if (palindrome > target)
            {
                return palindrome;
            }
        }

        /*
        Restore characters and move backward.

        We want to find the rightmost position where
        we can place a character greater than target[i].
        */
        int start = min(i, leftLen - 1);

        for (int pos = start; pos >= 0; pos--)
        {
            // Restore character if this position
            // was already matched
            if (pos < (int)left.size())
            {
                count[left.back() - 'a']++;
                left.pop_back();
            }

            int targetChar = target[pos] - 'a';

            // Find smallest available character > target[pos]
            for (int ch = targetChar + 1; ch < 26; ch++)
            {
                if (count[ch] > 0)
                {
                    left.push_back('a' + ch);
                    count[ch]--;

                    // Fill remaining positions with
                    // lexicographically smallest characters
                    for (int c = 0; c < 26; c++)
                    {
                        while (count[c] > 0)
                        {
                            left.push_back('a' + c);
                            count[c]--;
                        }
                    }

                    // Construct palindrome
                    string right = left;
                    reverse(right.begin(), right.end());

                    if (midChar != '\0')
                        return left + midChar + right;

                    return left + right;
                }
            }
        }

        return "";
    }
};

int main()
{
    string str = "baba";
    string target = "abba";

    Solution obj;

    cout << obj.lexPalindromicPermutation(str, target) << endl;

    return 0;
}