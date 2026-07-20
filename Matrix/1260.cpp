#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<vector<int>> solve(vector<vector<int>> &grid, int k)
    {
        int rows = grid.size();
        int cols = grid[0].size();

        vector<vector<int>> temp = grid;

        // shift one time to right
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                int newRow = (i * cols + j + 1) / cols;
                int newCol = (i * cols + j + 1) % cols;

                if (newRow == rows)
                {
                    newRow = 0;
                    newCol = 0;
                }

                temp[newRow][newCol] = grid[i][j];
            }
        }

        return temp;
    }
    vector<vector<int>> shiftGrid(vector<vector<int>> &grid, int k)
    {
        int l = grid.size();
        int r = grid[0].size();

        k %= (l * r);
        cout << "K: " << k << endl;
        vector<vector<int>> ans = grid;
        for (int i = 0; i < k; i++)
        {
            ans = solve(ans, i);
        }
        return ans;
    }
};

int main()
{
    vector<vector<int>> grid = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int k = 2;

    Solution s;
    vector<vector<int>> res = s.shiftGrid(grid, k);

    for (auto val : res)
    {
        for (auto v : val)
        {
            cout << v << " ";
        }
        cout << endl;
    }

    return 0;
}