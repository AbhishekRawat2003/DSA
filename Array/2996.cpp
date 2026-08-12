#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

class Solution
{
public:
    int missingInteger(vector<int> &nums)
    {
        // sort(nums.begin(), nums.end());
        unordered_set<int> st(nums.begin(), nums.end());
        int sum = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {

            if (nums[i] == nums[i - 1] + 1)
            {
                sum += nums[i];
            }
            else
            {
                break;
            }
        }
        cout << "sum: " << sum << endl;
        while (st.count(sum))
        {
            sum++;
        }

        return sum;
    }
};
int main()
{
    vector<int> nums = {3,4,5,1,12,14,13};
    Solution s;
    cout << s.missingInteger(nums) << endl;

    return 0;
}