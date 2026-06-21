#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> nums = {0, 1, 0};
    // int peak = nums[0];
    int n = nums.size();
    for (int i = 1; i < n; i++)
    {
        // if (i != 0 and i != n)
        // {
        //     if (peak > nums[i - 1] && peak > nums[i + 1])
        //     {
        //         cout << i << endl;
        //     }
        // }
        if ((i == 0 || nums[i] > nums[i - 1]) &&
            (i == n - 1 || nums[i] > nums[i + 1]))
        {
            cout << i << endl;
        }
    }
    return 0;
}