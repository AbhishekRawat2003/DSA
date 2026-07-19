#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;
class Solution
{
public:
    long long gcdSum(vector<int> &nums)
    {
        int mx = 0;
        vector<int> prefixGcd;
        for (auto val : nums)
        {
            mx = max(mx, val);
            prefixGcd.push_back(gcd(mx, val));
        }
        sort(prefixGcd.begin(), prefixGcd.end());
        int left = 0;
        int right = prefixGcd.size()-1;
        long long ans = 0;
        while (left < right)
        {
            ans += gcd(prefixGcd[left], prefixGcd[right]);
            left++;
            right--;
        }
        return ans;
    }
};
int main()
{
    vector<int> nums = {3,6,2,8};
    Solution s;
    cout << "Result: " << s.gcdSum(nums) << endl;
    return 0;
}