#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int firstStableIndex(vector<int> &nums, int k)
    {
        int n = nums.size();

        vector<int> prefixMax(n);

        prefixMax[0] = nums[0];

        for (int i = 1; i < n; i++)
        {
            prefixMax[i] = max(prefixMax[i - 1], nums[i]);
        }

        vector<int> suffixMin(n);

        suffixMin[n - 1] = nums[n - 1];

        for (int i = n - 2; i >= 0; i--)
        {
            suffixMin[i] = min(suffixMin[i + 1], nums[i]);
        }

    

        return -1;
    }
};

int main()
{
    vector<int> nums = {5, 0, 1, 4};
    int k = 3;

    Solution s;
    cout << s.firstStableIndex(nums, k);

    return 0;
}