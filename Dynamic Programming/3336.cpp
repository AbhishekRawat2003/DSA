#include <iostream>
#include <vector>

#include <numeric>
using namespace std;

// class Solution
// {
// public:
//     static const int MOD = 1e9 + 7;

//     int solve(vector<int> &nums, int i, int first, int second,
//               vector<vector<vector<int>>> &dp)
//     {
//         if (i == nums.size())
//         {
//             return (first != 0 && second != 0 && first == second);
//         }

//         if (dp[i][first][second] != -1)
//             return dp[i][first][second];

//         long long skip = solve(nums, i + 1, first, second, dp);

//         long long take1 = solve(nums, i + 1,
//                                 gcd(first, nums[i]), second, dp);

//         long long take2 = solve(nums, i + 1,
//                                 first, gcd(second, nums[i]), dp);

//         return dp[i][first][second] =
//                    (skip + take1 + take2) % MOD;
//     }

//     int subsequencePairCount(vector<int> &nums)
//     {
//         vector<vector<vector<int>>> dp(
//             nums.size(),
//             vector<vector<int>>(201, vector<int>(201, -1)));

//         return solve(nums, 0, 0, 0, dp);
//     }
// };
using namespace std;

class Solution
{
public:
    static const int MOD = 1e9 + 7;

    int subsequencePairCount(vector<int>& nums)
    {
        int n = nums.size();

        vector<vector<vector<int>>> dp(
            n + 1,
            vector<vector<int>>(201, vector<int>(201, 0))
        );

        dp[0][0][0] = 1;

        for (int i = 0; i < n; i++)
        {
            for (int g1 = 0; g1 <= 200; g1++)
            {
                for (int g2 = 0; g2 <= 200; g2++)
                {
                    if (dp[i][g1][g2] == 0)
                        continue;

                    // Skip
                    dp[i + 1][g1][g2] =
                        (dp[i + 1][g1][g2] + dp[i][g1][g2]) % MOD;

                    // Put in first subsequence
                    int ng1 = gcd(g1, nums[i]);
                    dp[i + 1][ng1][g2] =
                        (dp[i + 1][ng1][g2] + dp[i][g1][g2]) % MOD;

                    // Put in second subsequence
                    int ng2 = gcd(g2, nums[i]);
                    dp[i + 1][g1][ng2] =
                        (dp[i + 1][g1][ng2] + dp[i][g1][g2]) % MOD;
                }
            }
        }

        int ans = 0;
        for (int g = 1; g <= 200; g++)
        {
            ans = (ans + dp[n][g][g]) % MOD;
        }

        return ans;
    }
};
int main()
{
    vector<int> nums = {1, 2, 3, 4};
    Solution s;
    int res = s.subsequencePairCount(nums);
    cout << "Result: " << res << endl;
    return 0;
}