// 1046. Last Stone Weight
// You are given an array of integers stones where stones[i] is the weight of the ith stone.

// We are playing a game with the stones. On each turn, we choose the heaviest two stones and smash them together. Suppose the heaviest two stones have weights x and y with x <= y. The result of this smash is:

// If x == y, both stones are destroyed, and
// If x != y, the stone of weight x is destroyed, and the stone of weight y has new weight y - x.
// At the end of the game, there is at most one stone left.

// Return the weight of the last remaining stone. If there are no stones left, return 0

#include <iostream>
#include <vector>
#include <queue>
using namespace std;
class Solution
{
public:
    int lastStoneWeight(vector<int> &stones)
    {
        priority_queue<int> maxHeap(stones.begin(), stones.end());
        while (maxHeap.size() > 1)
        {
            int stone1 = maxHeap.top();
            maxHeap.pop();
            int stone2 = maxHeap.top();
            maxHeap.pop();
            if (stone1 != stone2)
            {
                maxHeap.push(stone1 - stone2);
            }
        }
        return maxHeap.empty() ? 0 : maxHeap.top();
    }
};
int main()
{
    // vector<int> nums = {2, 7, 4, 1, 8, 1};
    vector<int> nums = {1, 1};
    Solution s;
    int result = s.lastStoneWeight(nums);
    cout << "Result: " << result << endl;
    return 0;
}