#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int maximumProduct(vector<int> &nums)
    {
        int n=nums.size();
        sort(nums.begin(), nums.end());
        reverse(nums.begin(), nums.end());
        int mul1 = nums[0] * nums[1] * nums[2];
        int mul2 = nums[0] * nums[n - 2] * nums[n-1];
        return max(mul1, mul2);
    }
};

int main()
{
    vector<int> nums = {-100, -98, -1, 2, 3, 4};
    Solution s;
    cout << s.maximumProduct(nums) << endl;
    return 0;
}