#include <iostream>
#include <vector>
#include <cstring>
#include<climits>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int n;
    int t[2][101][101];

    int solve(vector<int>& piles, int person, int i, int m)
    {
        if (i >= n)
            return 0;

        if (t[person][i][m] != -1)
            return t[person][i][m];

        int result;

        if (person == 1)
        {
            result = 0;
        }
        else
        {
            result = INT_MAX;
        }

        int stones = 0;

        for (int x = 1; x <= min(2 * m, n - i); x++)
        {
            stones += piles[i + x - 1];

            if (person == 1)
            {
                result = max(
                    result,
                    stones + solve(piles, 0, i + x, max(m, x))
                );
            }
            else
            {
                result = min(
                    result,
                    solve(piles, 1, i + x, max(m, x))
                );
            }
        }

        return t[person][i][m] = result;
    }

    int stoneGameII(vector<int>& piles)
    {
        n = piles.size();

        memset(t, -1, sizeof(t));

        return solve(piles, 1, 0, 1);
    }
};

int main()
{
    vector<int> piles = {2, 7, 9, 4, 4};

    Solution s;

    cout << s.stoneGameII(piles) << endl;

    return 0;
}