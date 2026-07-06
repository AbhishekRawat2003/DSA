#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <queue>
using namespace std;

class Solution {
public:
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online,
                         long long k) {
        int n = (int)online.size();
        
        // Build adjacency list, skipping edges involving offline intermediate nodes
        vector<vector<pair<int,int>>> adj(n); // adj[u] = {v, cost}
        for (auto& e : edges) {
            int u = e[0], v = e[1], cost = e[2];
            bool uOk = (u == 0 || online[u]);
            bool vOk = (v == n - 1 || online[v]);
            if (uOk && vOk) {
                adj[u].push_back({v, cost});
            }
        }
        
        // Collect candidate thresholds (distinct edge costs)
        vector<int> costs;
        costs.reserve(edges.size());
        for (auto& e : edges) costs.push_back(e[2]);
        sort(costs.begin(), costs.end());
        costs.erase(unique(costs.begin(), costs.end()), costs.end());
        
        auto feasible = [&](int T) -> bool {
            vector<long long> dist(n, LLONG_MAX);
            vector<bool> visited(n, false);
            dist[0] = 0;
            priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<>> pq;
            pq.push({0, 0});
            while (!pq.empty()) {
                auto [d, node] = pq.top(); pq.pop();
                if (visited[node]) continue;
                visited[node] = true;
                if (node == n - 1) return d <= k;
                for (auto& [nxt, cost] : adj[node]) {
                    if (cost >= T && !visited[nxt]) {
                        long long nd = d + cost;
                        if (nd < dist[nxt]) {
                            dist[nxt] = nd;
                            pq.push({nd, nxt});
                        }
                    }
                }
            }
            return dist[n - 1] <= k;
        };
        
        int lo = 0, hi = (int)costs.size() - 1;
        int ans = -1;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (feasible(costs[mid])) {
                ans = costs[mid];
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        
        return ans;
    }
};
int main() {
  vector<vector<int>> edges = {{{0, 1, 5}, {1, 3, 10}, {0, 2, 3}, {2, 3, 4}}};
  vector<bool> online = {true, true, true, true};
  long long k = 10;
  Solution s;
  int res = s.findMaxPathScore(edges, online, k);
  cout << res << endl;
  return 0;
}