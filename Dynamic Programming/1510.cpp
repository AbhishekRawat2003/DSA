#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    bool winnerSquareGame(int n)
    {
        vector<bool> dp(n + 1, false);

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j * j <= i; j++)
            {
                int sq = j * j;
                if (dp[i - sq] == false)
                    dp[i] = true;
            }
        }
        return dp[n];
    }
};
int main()
{

    long long n = 10e9;
    Solution s;
    cout << s.winnerSquareGame(n) << endl;
    return 0;
}