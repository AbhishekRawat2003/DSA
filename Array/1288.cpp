#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int removeCoveredIntervals(vector<vector<int>> &intervals) {

    sort(intervals.begin(), intervals.end(),
         [](vector<int> &a, vector<int> &b) {
           if (a[0] == b[0])
             return a[1] > b[1];
           return a[0] < b[0];
         });

    int count = 0;
    int maxEnd = 0;

    for (auto &interval : intervals) {
      if (interval[1] > maxEnd) {
        cout << interval[1] << endl;
        count++;
        maxEnd = interval[1];
      }
    }

    return count;
  }
};
int main() {
  vector<vector<int>> nums = {{1, 4}, {3, 6}, {2, 8}};
  Solution s;
  int res = s.removeCoveredIntervals(nums);
  cout << res << endl;
  return 0;
}