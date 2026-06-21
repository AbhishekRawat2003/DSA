// all possible numbers.
#include <iostream>
#include <vector>

using namespace std;
void solve(vector<int> nums, int idx)
{
    if (idx == nums.size())
    {
        for (int val : nums)
        {
            cout << val << " ";
        }
        cout << endl;
        return;
    }
    for (int i = idx; i < nums.size(); i++)
    {
        swap(nums[idx], nums[i]);

        solve(nums, idx + 1);

        // backtrack
        swap(nums[idx], nums[i]);
    }
}
int main()
{

    vector<int> nums = {1, 2, 3,4};
    solve(nums, 0);

    return 0;
}