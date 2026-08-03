#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;
class Solution
{
public:
    string stoneGameIII(vector<int> &stoneValue)
    {
        int n = stoneValue.size();
        vector<int> dp(n + 1, 0);

        for (int i = n - 1; i >= 0; i--)
        {
            int best = INT_MIN;
            int sum = 0;
            for (int k = 0; k < 3 && i + k < n; k++)
            {
                sum += stoneValue[i + k];
                best = max(best, sum - dp[i + k + 1]);
            }
            dp[i] = best;
        }
        if (dp[0] > 0)
            return "Alice";
        if (dp[0] < 0)
            return "Bob";
        return "Tie";
    }
};

int main()
{
    vector<int> stoneValue = {1, 2, 3, 7};
    Solution s;
    cout << s.stoneGameIII(stoneValue) << endl;
    return 0;
}