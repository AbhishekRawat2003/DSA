#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution
{
public:
    int minimumDeletions(vector<int> &nums)
    {
        int n = nums.size();
        cout << n << endl;
        int maxNum = INT_MIN;
        int minNum = INT_MAX;
        int maxIdx = 0;
        int minIdx = 0;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] > maxNum)
            {
                maxNum = nums[i];
                maxIdx = i;
            }
            if (nums[i] < minNum)
            {
                minNum = nums[i];
                minIdx = i;
            }
        }
        int front = max(maxIdx,minIdx)+1;
        int back= n-min(maxIdx,minIdx);
        int minFrontMaxBack =
            (minIdx + 1) + (n - maxIdx);
        int maxFrontMinBack =
            (maxIdx + 1) + (n - minIdx);

            return min({front, back, minFrontMaxBack, maxFrontMinBack});

    }
};
int main()
{
    vector<int> nums = {
        2, 10, 7, 5, 4, 1, 8, 6};
    Solution s;
    cout << s.minimumDeletions(nums) << endl;
    return 0;
}