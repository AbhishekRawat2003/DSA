#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    // int uniqueXorTriplets(vector<int> &nums)
    // {
    //     int n=nums.size();
    //     if(n<=2) return n;
    //     return 1<< (32-__builtin_clz(n));
    // }

    int uniqueXorTriplets(vector<int> nums)
    {
        int n = nums.size();
        if (n <= 2)
            return n;
        int power = 1;
        while (power < n)
        {
            power <<= 1;
        }

        return power;
    }
};
int main()
{
    vector<int> nums = {
        1,
        2,
        3};
    Solution s;
    cout << s.uniqueXorTriplets(nums) << endl;

    return 0;
}