#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
  vector<vector<int>> intervalIntersection(vector<vector<int>> &firstList,
                                           vector<vector<int>> &secondList) {
    vector<vector<int>> res;
    int left = 0;
    int right = 0;
    while (firstList.size() <= secondList.size()) {
      // case1
      if (secondList[right][0] < firstList[left][1] &&
          secondList[right][1] > firstList[left][0]) { // intersection
        // res.push_back({max(secondList)})
      }
    }
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