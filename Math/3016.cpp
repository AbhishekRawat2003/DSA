#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
    int minimumPushes(string word)
    {
        vector<int> freq(26, 0);
        for (char c : word)
        {
            freq[c - 'a']++;
        }
        sort(freq.rbegin(), freq.rend());
        for (auto val : freq)
            cout << val << " ";
        int ans = 0;
        for (int i = 0; i < 26; ++i)
        {
            if (freq[i] == 0)
                break;
            int pushes = (i / 8) + 1;
            ans += freq[i] * pushes;
        }
        return ans;
    }
};
int main()
{
    string str = "xyzxyzxyzxyzmn";
    Solution s;
    cout << s.minimumPushes(str) << endl;
    return 0;
}