#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int mn = *min_element(nums1.begin(), nums1.end());

        if (mn % 2 != 0)
            return true;

        for (int x : nums1) {
            if (x % 2 != 0)
                return false;
        }

        return true;
    }
};

int main(){
    vector<int> nums = {1,3,7};
    Solution s;
    cout<< s.uniformArray(nums)<<endl;
    return 0; 
}