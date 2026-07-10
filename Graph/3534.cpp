#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<int> pathExistenceQueries(
        int n,
        vector<int>& nums,
        int maxDiff,
        vector<vector<int>>& queries
    ) {

        vector<pair<int,int>> arr;

        // value, original index
        for(int i = 0; i < n; i++){
            arr.push_back({nums[i], i});
        }

        sort(arr.begin(), arr.end());

        vector<int> pos(n);
        vector<int> value(n);

        // sorted position -> original index mapping
        for(int i = 0; i < n; i++){
            value[i] = arr[i].first;
            pos[arr[i].second] = i;
        }


        // Step 1: Find farthest reachable position
        vector<int> nxt(n);

        int r = 0;

        for(int l = 0; l < n; l++){

            while(r + 1 < n &&
                  value[r+1] - value[l] <= maxDiff){
                r++;
            }

            nxt[l] = r;

            if(r == l)
                r++;
        }


        // Step 2: Binary lifting table

        int LOG = 17; // because n <= 1e5, use 18
        while((1 << LOG) <= n)
            LOG++;

        vector<vector<int>> up(LOG, vector<int>(n));


        for(int i = 0; i < n; i++){
            up[0][i] = nxt[i];
        }


        for(int j = 1; j < LOG; j++){
            for(int i = 0; i < n; i++){
                up[j][i] = up[j-1][up[j-1][i]];
            }
        }


        vector<int> ans;


        // Step 3: Answer queries

        for(auto &q: queries){

            int start = pos[q[0]];
            int end = pos[q[1]];

            if(start > end)
                swap(start,end);


            // same node
            if(start == end){
                ans.push_back(0);
                continue;
            }


            int curr = start;
            int steps = 0;


            // Binary lifting
            for(int j = LOG-1; j >= 0; j--){

                if(up[j][curr] < end){
                    curr = up[j][curr];
                    steps += (1 << j);
                }
            }


            // one final jump
            if(up[0][curr] >= end){
                steps++;
                ans.push_back(steps);
            }
            else{
                ans.push_back(-1);
            }
        }


        return ans;
    }
};
int main() {
  int n = 5;
  vector<int> nums = {1,8,4,3,2};
  int maxDiff = 3;
  vector<vector<int>> queries = {{0, 3}, {2, 4}};
  Solution s;
  vector<int> res = s.pathExistenceQueries(n, nums, maxDiff, queries);
  for (auto val : res) {
    cout << val << " ";
  }
  cout << endl << endl;
  return 0;
}