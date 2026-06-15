// Problem statement
// You have been given a queue of integers. You need to rearrange the elements
// of the queue by interleaving the elements of the first half of the queue with
// the second half.

// Note :
// The given queue will always be of even length.
// For example :
// If N= 10
// and Q = [10, 20, 30, 40, 50, 60, 70, 80, 90, 100]
// then the output will be
//  Q = [10, 60, 20, 70, 30, 80, 40, 90, 50, 100]

#include <iostream>
#include <queue>
#include <stack>
#include <vector>
using namespace std;
class Solution {
public:
  stack<int> interleavingElement(vector<int> nums, int n) {
    int mid = n / 2;
    queue<int> q1;
    queue<int> q2;
    stack<int> st;
    // first half
    for (int i = 0; i < mid; i++) {
      q1.push(nums.back());
      nums.pop_back();
    }
    // second half
    for (int i = mid; i < n; i++) {
      q2.push(nums.back());
      nums.pop_back();
    }
    cout << "q1: ";
    queue<int> temp1 = q1;
    while (!temp1.empty()) {
      cout << temp1.front() << " ";
      temp1.pop();
    }
    cout << endl;

    cout << "q2: ";
    queue<int> temp2 = q2;
    while (!temp2.empty()) {
      cout << temp2.front() << " ";
      temp2.pop();
    }
    cout << endl;

    // Insert to stack
    for (int i = 0; i < n; i++) {
      if (i % 2 == 0) {
        st.push(q1.front());
        q1.pop();
      } else {
        st.push(q2.front());
        q2.pop();
      }
    }

    return st;
  }
};

int main() {
  vector<int> nums = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
  int n = 10;
  Solution s;
  stack<int> result = s.interleavingElement(nums, n);
  while (!result.empty()) {
    cout << result.top() << " ";
    result.pop();
  }

  cout << endl;
  return 0;
}
