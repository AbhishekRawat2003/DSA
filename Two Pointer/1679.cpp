#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int maxOperations(vector<int> &nums, int k)
    {
        // unordered_map<int, int> mp;
        // int ans = 0;
        // for (auto b : nums)
        // {
        //     int a = k - b;
        //     if (mp[a ]>0)
        //     {
        //         ans++;
        //         mp[a]--;
        //     }
        //     else
        //     {
        //         mp[b]++;
        //     }
        // }
        // return ans;

        sort(nums.begin(), nums.end());
        int ans = 0;
        int l = 0;
        int r = nums.size() - 1;
        while (l < r)
        {
            if (nums[l] + nums[r] == k)
            {
                ans++;
                l++;
                r--;
            }
            else if (nums[l] + nums[r] < k)
            {
                l++;
            }
            else
            {
                r--;
            }
        }
        return ans;
    }
};
int main()
{
    vector<int> nums = {1, 2, 3, 4};
    int k = 5;
    Solution s;
    cout << s.maxOperations(nums, k) << endl;
    return 0;
}