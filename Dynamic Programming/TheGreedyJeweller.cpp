#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution
{
public:
    int solve(int i1, int j1, int i2, vector<vector<int>> &mat, vector<vector<vector<int>>> &dp)
    {
        int n = mat.size();
        int j2 = i1 + j1 - i2;

        if (i1 >= n || j1 >= n || i2 >= n || j2 >= n)
            return INT_MIN;

        if (mat[i1][j1] == -1 || mat[i2][j2] == -1)
            return INT_MIN;

        if (i1 == n - 1 && j1 == n - 1)
            return mat[i1][j1];

        if (dp[i1][j1][i2] != -1)
            return dp[i1][j1][i2];

        int best = INT_MIN;
        best = max(best, solve(i1 + 1, j1, i2 + 1, mat, dp));
        best = max(best, solve(i1 + 1, j1, i2, mat, dp));
        best = max(best, solve(i1, j1 + 1, i2 + 1, mat, dp));
        best = max(best, solve(i1, j1 + 1, i2, mat, dp));

        if (best == INT_MIN)
            return dp[i1][j1][i2] = INT_MIN;

        int gold = mat[i1][j1];
        if (i1 != i2 || j1 != j2)
            gold += mat[i2][j2];

        return dp[i1][j1][i2] = best + gold;
    }

    int greedyJeweller(int n, vector<vector<int>> &mat)
    {
        if (mat[0][0] == -1 || mat[n - 1][n - 1] == -1)
            return 0;

        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(n, -1)));

        int ans = solve(0, 0, 0, mat, dp);

        if (ans < 0)
            return 0;   // no valid path -> 0, not -1

        return ans;
    }
};


int main()
{
    vector<vector<int>> mat = {
        {0, 1, 0},
        {1, 0, 1},
        {1, 0, 1}};

    int N = 3;

    Solution s;
    cout << s.greedyJeweller(N, mat)<<endl;
}