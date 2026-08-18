#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution
{
public:
    int largestInteger(vector<int> &nums, int k)
    {
        int n = nums.size();

        unordered_map<int, int> freq;
        for (int i = 0; i < n; i++)
        {
            freq[nums[i]]++;
        }

        int maxElement = -1;
        int maxElementFreq = -1;

        for (auto x : freq)
        {
            if (x.second == 1)
            {
                maxElementFreq = max(maxElementFreq, x.first);
            }
            maxElement = max(maxElement, x.first);
        }

        if (k == 1)
            return maxElementFreq;
        else if (k == n)
            return maxElement;
        else
        {
            if (freq[nums[0]] == 1 && freq[nums[n - 1]] == 1)
            {
                return max(nums[0], nums[n - 1]);
            }
            else if (freq[nums[n - 1]] == 1)
                return nums[0];
            else if (freq[nums[0]] == 1)
                return nums[n - 1];
        }
        return -1;
    }
};

int main()
{
    vector<int> nums = {3, 9, 2, 1, 7};
    int k = 3;

    Solution s;

    cout << s.largestInteger(nums, k);

    return 0;
}