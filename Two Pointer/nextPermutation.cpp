#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void nextPermutation(vector<int> &nums)
{
    int pivot = -1;

    // Find Pivot
    int n = nums.size() - 1;

    while (n > 0)
    {
        if (nums[n] > nums[n - 1])
        {
            pivot = n - 1;
            break;
        }

        n--;
    }

    // No pivot case
    if (pivot == -1)
    {
        reverse(nums.begin(), nums.end());

        for (auto val : nums)
        {
            cout << val;
        }

        cout << endl;
        return;
    }

    int smallestIndex = pivot + 1;

    for (int i = pivot + 1; i < nums.size(); i++)
    {
        if (nums[i] > nums[pivot] &&
            nums[i] <= nums[smallestIndex])
        {
            smallestIndex = i;
        }
    }

    swap(nums[pivot], nums[smallestIndex]);

    sort(nums.begin() + pivot + 1, nums.end());

    for (auto val : nums)
    {
        cout << val;
    }

    cout << endl;
}

int main()
{
    vector<int> nums = {1, 2, 3, 6, 5, 4};
    vector<int> nums1 = {3, 2, 1};

    nextPermutation(nums);
    nextPermutation(nums1);

    return 0;
}