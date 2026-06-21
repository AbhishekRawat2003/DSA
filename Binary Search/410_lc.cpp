// 410. Split Array Largest Sum
// Given an integer array nums and an integer k, split nums into k non-empty subarrays such that the largest sum of any subarray is minimized.

// Return the minimized largest sum of the split.

// A subarray is a contiguous part of the array.

// Example 1:

// Input: nums = [7,2,5,10,8], k = 2
// Output: 18
// Explanation: There are four ways to split nums into two subarrays.
// The best way is to split it into [7,2,5] and [10,8], where the largest sum among the two subarrays is only 18.

#include <iostream>
#include <vector>
using namespace std;
bool isValid(vector<int> nums, int largestSubarray, int k)
{
    int largest = 0;
    int split = 1;
    for (int i = 0; i < nums.size(); i++)
    {
        if (largest + nums[i] <= largestSubarray)
        {
            largest += nums[i];
        }
        else
        {
            split++;
            largest = nums[i];
        }
    }
    return split > k ? false : true;
}
int minimizedLargestSum(vector<int> nums, int k)
{
    int start = 0;
    for (auto var : nums)
    {
        if (var > start)
        {
            start = var;
        }
    }
    int end = 0;
    for (auto var : nums)
    {
        end += var;
    }
    int ans = -1;
    while (start <= end)
    {
        int mid = (start + end) / 2;
        if (isValid(nums, mid, k))
        {
            ans = mid;
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
    return ans;
}

int main()
{
    vector<int> nums = {7, 2, 5, 10, 8};
    int k = 2;
    int ans = minimizedLargestSum(nums, k);
    cout << ans << endl;
    return 0;
}