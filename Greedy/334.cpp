#include <iostream>
#include <vector>
#include<climits>

using namespace std;

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int first = INT_MAX;
        int second = INT_MAX;

        for (int num : nums) {
            if (num <= first) {
                first = num;
            }
            else if (num <= second) {
                second = num;
            }
            else {
                return true;
            }
        }

        return false;
    }
};

int main()
{
    // vector<int> nums = {2, 1, 5, 0, 4, 6};
    // vector<int> nums= {5,4,3,2,1};
    vector<int> nums = {2, 4, -2, -3};
    Solution s;
    cout << s.increasingTriplet(nums);
    cout << endl;
    return 0;
}