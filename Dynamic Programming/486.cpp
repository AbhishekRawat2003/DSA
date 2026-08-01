#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    bool predictTheWinner(vector<int> &nums)
    {
       int n = nums.size();
        vector<int> dp(nums.begin(), nums.end());

        for (int len = 2; len <= n; len++) {
            for (int i = 0; i + len - 1 < n; i++) {
                int j = i + len - 1;
                dp[i] = max(nums[i] - dp[i + 1], nums[j] - dp[i]);
            }
        }

        return dp[0] >= 0;

    }
};
int main()
{
    vector<int> nums = {1, 4, 5, 6};
    Solution s;
    cout << s.predictTheWinner(nums) << endl;
    return 0;
}