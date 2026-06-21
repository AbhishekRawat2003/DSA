// Single Element in a Sorted Array
// nums = [1,1,2,3,3,4,4,8,8]
// Output: 2
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
int singleNonDuplicate(vector<int> &nums)
{
    unordered_map<int, int> mp;

    for (int i = 0; i < nums.size(); i++)
    {

        mp[nums[i]]++;
    }
    for(auto it:mp){
        if(it.second==1){
            return it.first;
        }
    }
    return -1;
}

int main()
{
    vector<int> nums = {1, 1, 2, 3, 3, 4, 4, 8, 8};
    int result = singleNonDuplicate(nums);
    cout << result << endl;
    return 0;
}