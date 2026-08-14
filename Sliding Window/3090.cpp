#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    int maximumLengthSubstring(string s)
    {

        unordered_map<int, int> mp;

        int left = 0;
        int n = s.size();
        int pvt = 0;
        int ans = 0;
        while (pvt < n)
        {
            mp[s[pvt]]++;
            while (mp[s[pvt]] > 2)
            {
                mp[s[left]]--;
                left++;
            }
            pvt++;
            ans = max(ans, pvt-left);
        }
        return ans;
    }
};
int main()
{
    string str = "aaaa";
    Solution s;
    cout << s.maximumLengthSubstring(str) << endl;
    return 0;
}