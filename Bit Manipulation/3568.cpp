#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include<array>
using namespace std;
class Solution
{
public:
    int minMoves(vector<string> &classroom, int energy)
    {
        int m = classroom.size();
        int n = classroom[0].size();
        int sr, sc; // starting row, starting column.
        vector<pair<int, int>> litter;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (classroom[i][j] == 'S')
                {
                    sr = i;
                    sc = j;
                }
                if (classroom[i][j] == 'L')
                {
                    litter.push_back({i, j});
                }
            }
        }
        int k = litter.size();
        vector<vector<int>> lt(m, vector<int>(n, -1));
        if (k == 0)
            return 0;
        for (int i = 0; i < k; i++)
        {
            lt[litter[i].first][litter[i].second] = i;
        }
        cout << "Lt: " << endl;

        for (int i = 0; i < k; i++)
        {
            cout << lt[litter[i].first][litter[i].second] << " ";
        }
        cout << endl;
        cout << "Lt Matrix:" << endl;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << lt[i][j] << " ";
            }
            cout << endl;
        }

        int targetMask = (1 << k) - 1;
        vector<vector<vector<int>>> best(m, vector<vector<int>>(n, vector<int>(1 << k, -1)));

        queue<array<int, 5>> q;
        q.push({sr, sc, 0, energy, 0});
        best[sr][sc][0] = energy;

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        while (!q.empty())
        {
            auto [r, c, mask, currentEnergy, moves] = q.front();
            q.pop();

            if (mask == targetMask)
            {
                return moves;
            }

            if (currentEnergy == 0)
            {
                continue;
            }

            for (int d = 0; d < 4; d++)
            {
                int nr = r + dr[d];
                int nc = c + dc[d];

                if (nr < 0 || nr >= m || nc < 0 || nc >= n ||
                    classroom[nr][nc] == 'X')
                {
                    continue;
                }

                int newEnergy = currentEnergy - 1;
                int newMask = mask;

                if (lt[nr][nc] != -1)
                {
                    newMask |= (1 << lt[nr][nc]);
                }

                if (classroom[nr][nc] == 'R')
                {
                    newEnergy = energy;
                }

                if (best[nr][nc][newMask] >= newEnergy)
                {
                    continue;
                }

                best[nr][nc][newMask] = newEnergy;

                q.push({nr, nc, newMask, newEnergy, moves + 1});
            }
        }
        return -1;
    }
};
int main()
{
    vector<string> classroom = {"S.", "XL"};
    int energy = 2;
    Solution s;
    cout << s.minMoves(classroom, energy);
    return 0;
}