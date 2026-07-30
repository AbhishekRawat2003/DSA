#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;
class Solution
{
public:
    int minimumPushes(string word)
    {
        vector<int> count(26, 0);
        for (char c : word)
        {
            count[c - 'a']++;
        }

        sort(count.rbegin(), count.rend());
        int ans = 0;
        for (int i = 0; i < 26; ++i)
        {
            if (count[i] == 0)
                break;
            int pushes = (i / 8) + 1;
            ans += count[i] * pushes;
        }

        return ans;
    }
};
int main()
{
    string word = "xycdefghij";
    Solution s;
    cout << s.minimumPushes(word) << endl;
    return 0;
}