// 881. Boats to Save People
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int numRescueBoats(vector<int> &people, int limit) {
    sort(people.begin(), people.end());
    int boats = 0;
    int left = 0;
    int right = people.size() - 1;
     while (left <= right) {
        if (people[left] + people[right] <= limit) {
            left++;   // lightest can pair with heaviest
        }
        right--;
        boats++;
    }
    return boats;
  }
};
int main() {
  vector<int> people = {3, 5,3,4};
  int limit = 5;
  Solution s;
  int result = s.numRescueBoats(people, limit);
  cout << "Number of Boats required to save people is " << result << endl;
  return 0;
}