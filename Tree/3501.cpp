#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath> 
using namespace std;

// class Solution
// {
// public:
//     int solve(string &s, int m, int n, vector<int> &prefix)
//     {
//         int ones = 0;
//         int prevSum = -1;
//         int best = 0;
//         int outside = prefix[m] + (prefix[s.size()] - prefix[n + 1]);
//         while (m <= n)
//         {
//             if (s[m] == '1')
//             {
//                 ones++;
//                 m++;
//             }
//             else
//             {
//                 int curr = 0;
//                 while (m <= n && s[m] == '0')
//                 {
//                     curr++;
//                     m++;
//                 }

//                 if (prevSum > 0 && ones > 0)
//                 {
//                     best = max(best, prevSum + curr);
//                 }
//                 prevSum = curr;
//             }
//         }

//         return outside + best + ones;
//     }

//     vector<int> maxActiveSectionsAfterTrade(string s, vector<vector<int>> &queries)
//     {
//         vector<int> ans;
//         vector<int> prefix(s.size() + 1, 0);
//         for (int i = 0; i < s.size(); i++)
//         {
//             prefix[i + 1] = prefix[i] + (s[i] == '1');
//         }
//         for (auto &val : queries)
//         {
//             ans.push_back(solve(s, val[0], val[1], prefix));
//         }

//         return ans;
//     }
// };
class SparseTable {
public:
    explicit SparseTable(const vector<int>& arr) : n(arr.size()) {
        int levels = n > 0 ? (int)floor(log2(n)) + 1 : 1;
        table.assign(levels, vector<int>(max(n, 1)));
        if (n > 0) table[0] = arr;
        for (int j = 1; (1 << j) <= n; ++j) {
            int half = 1 << (j - 1);
            for (int i = 0; i + (1 << j) <= n; ++i)
                table[j][i] = max(table[j - 1][i], table[j - 1][i + half]);
        }
    }
    // inclusive range max over arr[lo..hi]
    int query(int lo, int hi) const {
        int len = hi - lo + 1;
        int k = (int)floor(log2(len));
        return max(table[k][lo], table[k][hi - (1 << k) + 1]);
    }
private:
    int n;
    vector<vector<int>> table;
};

class Solution {
public:
    vector<int> maxActiveSectionsAfterTrade(string s, vector<vector<int>>& queries) {
        int n = s.size();
        int totalOnes = (int)count(s.begin(), s.end(), '1');

        vector<pair<int,int>> zeroGroups;      
        vector<int> nearZeroGroup(n, -1);
        for (int i = 0; i < n; ++i) {
            if (s[i] == '0') {
                if (i > 0 && s[i - 1] == '0') zeroGroups.back().second = i;
                else zeroGroups.push_back({i, i});
            }
            nearZeroGroup[i] = (int)zeroGroups.size() - 1;
        }

        vector<int> answers;
        answers.reserve(queries.size());
        if (zeroGroups.empty()) {
            answers.assign(queries.size(), totalOnes);
            return answers;
        }

        auto glen = [&](int k) { return zeroGroups[k].second - zeroGroups[k].first + 1; };

        int groupCount = (int)zeroGroups.size();
        vector<int> pairSum(max(groupCount - 1, 0));
        for (int k = 0; k < groupCount - 1; ++k)
            pairSum[k] = glen(k) + glen(k + 1);
        SparseTable sparse(pairSum);

        for (auto& q : queries) {
            int l = q[0], r = q[1];
            int gl = nearZeroGroup[l], gr = nearZeroGroup[r];

            int leftClip = -1, rightClip = -1;
            if (s[l] == '0') leftClip = zeroGroups[gl].second - l + 1;
            if (s[r] == '0') rightClip = r - zeroGroups[gr].first + 1;

            int best = totalOnes;

            int lo = gl + 1;
            int rawEnd = (s[r] == '1') ? gr : gr - 1;  
            int hi = rawEnd - 1;                        

            if (s[l] == '0' && s[r] == '0' && gl + 1 == gr) {
                best = max(best, totalOnes + leftClip + rightClip);
            } else if (lo <= hi) {
                best = max(best, totalOnes + sparse.query(lo, hi));
            }

            if (s[l] == '0' && lo <= rawEnd)
                best = max(best, totalOnes + leftClip + glen(gl + 1));
            if (s[r] == '0' && gl < gr - 1)
                best = max(best, totalOnes + rightClip + glen(gr - 1));

            answers.push_back(best);
        }

        return answers;
    }
};

int main()
{
    string s = "01";
    vector<vector<int>> query = {{0, 1}};

    string s1 = "0100";
    vector<vector<int>> query1 = {{0, 3}, {0, 2}, {1, 3}, {2, 3}};

    string s2 = "1000100";
    vector<vector<int>> query2 = {{1, 5}, {0, 6}, {0, 4}};

    Solution obj;

    vector<int> res = obj.maxActiveSectionsAfterTrade(s, query);
    vector<int> res1 = obj.maxActiveSectionsAfterTrade(s1, query1);
    vector<int> res2 = obj.maxActiveSectionsAfterTrade(s2, query2);

    for (auto val : res)
        cout << val << " ";
    cout << endl;

    for (auto val : res1)
        cout << val << " ";
    cout << endl;

    for (auto val : res2)
        cout << val << " ";
    cout << endl;

    return 0;
}