#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution
{
public:
    int countSpecialIntegers(vector<int> &nums)
    {
        unordered_set<int> seen;
        unordered_set<int> notSeen;

        int prev = nums[0];
        seen.insert(prev);

        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] != prev)
            {
                if (seen.count(nums[i]))
                {
                    notSeen.insert(nums[i]);
                }
            }
            seen.insert(nums[i]);
            prev = nums[i];
        }
        cout << endl;
        for (int num : seen)
        {
            cout << num << " ";
        }
        cout << endl;
        for (int num : notSeen)
        {
            cout << num << " ";
        }

        return seen.size() -
               notSeen.size();
    }
};

int main()
{
    vector<int> nums = {3, 3, 1, 2, 2, 1};
    Solution s;
    cout << s.countSpecialIntegers(nums);
    return 0;
}