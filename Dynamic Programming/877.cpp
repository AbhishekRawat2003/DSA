#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    bool stoneGame(vector<int> &piles)
    {
        int n = piles.size();
        vector<int> dp(piles.begin(), piles.end());

        for (int len = 2; len <= n; len++)
        {
            for (int i = 0; i + len - 1 < n; i++)
            {
                int j = i + len - 1;
                dp[i] = max(piles[i] - dp[i + 1], piles[j] - dp[i]);
            }
        }

        return dp[0] >= 0;
    }
};
int main()
{
    vector<int> piles = {2, 4, 5, 6, 7};
    Solution s;
    cout << s.stoneGame(piles) << endl;
    return 0;
}