#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int dp[501][501];

    int solve(int l, int r,
              vector<int>& stones,
              vector<int>& prefix)
    {
        if (l == r)
            return 0;

        if (dp[l][r] != -1)
            return dp[l][r];

        int ans = 0;
        for (int i = l; i < r; i++)
        {
            int leftSum =
                prefix[i + 1] - prefix[l];

            int rightSum =
                prefix[r + 1] - prefix[i + 1];

            if (leftSum < rightSum)
            {
                ans = max(
                    ans,
                    leftSum +
                    solve(l, i, stones, prefix)
                );
            }

            else if (rightSum < leftSum)
            {
                ans = max(
                    ans,
                    rightSum +
                    solve(i+1, r, stones, prefix)
                );
            }

            else
            {
                ans = max(
                    ans,
                    leftSum +
                    max(
                        solve(l, i, stones, prefix),
                        solve(i + 1, r, stones, prefix)
                    )
                );
            }
        }

        return dp[l][r] = ans;
    }

    int stoneGameV(vector<int>& stones)
    {
        int n = stones.size();

        vector<int> prefix(n + 1, 0);

        for (int i = 0; i < n; i++)
        {
            prefix[i + 1] =
                prefix[i] + stones[i];
        }

        memset(dp, -1, sizeof(dp));

        return solve(0, n - 1, stones, prefix);
    }
};

int main()
{
    vector<int> stones = {6, 2, 3, 4, 5, 5};

    Solution s;

    cout << s.stoneGameV(stones) << endl;

    return 0;
}