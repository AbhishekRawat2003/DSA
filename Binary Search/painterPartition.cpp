// Given an array arr[] and an integer k, where the array represents the boards and each element denotes the length of a board, and k painters are available to paint these boards. Each unit length of a board takes 1 unit of time to paint. Find the minimum time required to paint all the boards such that each painter paints only contiguous sections of the array. A painter can paint boards like [2, 3, 4], [1], or even no board, but cannot paint non-contiguous boards like [2, 4, 5].

// Examples:

// Input: arr[] = [5, 10, 30, 20, 15], k = 3
// Output: 35
// Explanation: The most optimal way will be: Painter 1 allocation : [5,10], Painter 2 allocation : [30], Painter 3 allocation : [20, 15], Job will be done when all painters finish i.e. at time = max(5 + 10, 30, 20 + 15) = 35

#include <iostream>
#include <vector>

using namespace std;

bool isValid(vector<int> nums, int maxAllowedPainter, int painters)
{
    int painter = 1;
    int time = 0;

    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] > maxAllowedPainter)
        {
            return false;
        }

        if (time + nums[i] <= maxAllowedPainter)
        {
            time += nums[i];
        }
        else
        {
            painter++;
            time = nums[i];
        }
    }

    // return painter <= painters;
    return painter > painters ? false : true;
}

int AllocatePainters(vector<int> nums, int painters)
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
        int mid = start + (end - start) / 2;

        if (isValid(nums, mid, painters))
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
    vector<int> nums = {5, 10, 30, 20, 15};

    int p = 3;

    int ans = AllocatePainters(nums, p);

    cout << "Minimum time required: " << ans << endl;

    return 0;
}