#include <iostream>
#include <vector>
#include <functional>  
using namespace std;

class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>> graph(n);

        for (auto &e : invocations) {
            graph[e[0]].push_back(e[1]);
        }

        vector<bool> suspicious(n, false);

        function<void(int)> dfs = [&](int node) {
            suspicious[node] = true;
            for (int nei : graph[node]) {
                if (!suspicious[nei])
                    dfs(nei);
            }
        };

        dfs(k);

        for (auto &e : invocations) {
            int u = e[0];
            int v = e[1];

            if (!suspicious[u] && suspicious[v]) {
                vector<int> ans;
                for (int i = 0; i < n; i++)
                    ans.push_back(i);
                return ans;
            }
        }
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (!suspicious[i])
                ans.push_back(i);
        }

        return ans;
    }
};

int main()
{
    int n = 4;
    int k = 1;
    vector<vector<int>> invocations = {{1, 2}, {0, 1}, {3, 2}};
    Solution s;
    vector<int> res = s.remainingMethods(n, k, invocations);
    for (auto val : res)
    {
        cout << val << " ";
    }
    return 0;
}