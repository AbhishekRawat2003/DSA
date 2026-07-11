#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    void dfs(int i, unordered_map<int, vector<int>> &adj,
             vector<bool> &visited, int &v, int &e)
    {
        visited[i] = true;
        v++;
        e += adj[i].size();

        for (int &ngbr : adj[i])
        {
            if (!visited[ngbr])
            {
                dfs(ngbr, adj, visited, v, e);
            }
        }
    }

    int countCompleteComponents(int n, vector<vector<int>> &edges)
    {
        unordered_map<int, vector<int>> adj;

        for (auto &edge : edges)
        {
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<bool> visited(n, false);
        int result = 0;

        for (int i = 0; i < n; i++)
        {
            if (visited[i])
                continue;

            int v = 0;
            int e = 0;

            dfs(i, adj, visited, v, e);

            // e is twice the number of edges
            if (v * (v - 1) == e)
            {
                result++;
            }
        }

        return result;
    }
};

int main()
{
    int n = 6;
    vector<vector<int>> edges = {
        {0, 1},
        {0, 2},
        {1, 2},
        {3, 4},
        {3, 5}};

    Solution s;
    cout << s.countCompleteComponents(n, edges) << endl;
    ;

    return 0;
}