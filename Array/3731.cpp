#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<int> findMissingElements(vector<int> &nums)
    {
        vector<int> ans;
        unordered_set<int> st;

        int low = nums[0];
        int high = nums[0];

        for (int val : nums)
        {
            st.insert(val);
            low = min(low, val);
            high = max(high, val);
        }

        for (int i = low + 1; i < high; i++)
        {
            if (st.find(i) == st.end())
            {
                ans.push_back(i);
            }
        }

        return ans;
    }
};

int main()
{
    vector<int> nums = {5, 1};

    Solution s;

    vector<int> result = s.findMissingElements(nums);

    for (int x : result)
    {
        cout << x << " ";
    }

    cout << endl;

    return 0;
}