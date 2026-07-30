#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int max1 = nums[nums.size()-1] - 1;
        int max2 = nums[nums.size()-2] - 1;

        return max1 * max2;
    }
};
int main()
{
    vector<int> nums = {3,4,5,2};
    Solution s;
    cout << s.maxProduct(nums) << endl;
    return 0;
}