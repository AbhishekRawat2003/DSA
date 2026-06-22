#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
  vector<vector<int>> intervalIntersection(vector<vector<int>> &firstList,
                                           vector<vector<int>> &secondList) {
    vector<vector<int>> res;
    int i = 0, j = 0;

    while (i < firstList.size() && j < secondList.size()) {

      int start = max(firstList[i][0], secondList[j][0]);
      int end = min(firstList[i][1], secondList[j][1]);

      if (start <= end) {
        res.push_back({start, end});
      }

      if (firstList[i][1] < secondList[j][1]) {
        i++;
      } else {
        j++;
      }
    }

    return res;
  }
};
int main() {
  vector<vector<int>> firstList = {{0, 2}, {5, 10}, {13, 23}, {24, 25}};
  vector<vector<int>> secondList = {{1, 5}, {8, 12}, {15, 24}, {25, 26}};
  Solution s;
  vector<vector<int>> result = s.intervalIntersection(firstList, secondList);
  for (auto val : result) {
    for (auto x : val) {
      cout << x << " ";
    }
    cout << endl;
  }

  return 0;
}