#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution
{
public:
    int uniqueXorTriplets(vector<int> &nums)
    {
        int n = nums.size();
        unordered_set<int> st;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int XOR = nums[i] ^ nums[j];
                st.insert(XOR);
            }
        }
        unordered_set<int> ans;
        for (int val : st)
        {
            for (int num : nums)
            {
                ans.insert(val ^ num);
            }
        }
        return ans.size();
    }
};
int main()
{
    vector<int> nums = {6, 8, 7, 9};
    Solution s;
    cout << s.uniqueXorTriplets(nums);
    cout << endl;

    return 0;
}