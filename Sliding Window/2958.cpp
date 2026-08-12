#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int maxSubarrayLength(vector<int> &nums, int k)
    {
        unordered_map<int, int> freq;
        int left = 0;
        int ans = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            freq[nums[i]]++;
            while (freq[nums[i]] > k)
            {
                freq[nums[left]]--;
                left++;
            }
            ans = max(ans, i - left + 1);
        }
        return ans;
    }
};
int main()
{
    vector<int> nums = {1, 4, 4, 3};
    int k = 1;
    Solution s;
    cout << s.maxSubarrayLength(nums, k) << endl;

    return 0;
}