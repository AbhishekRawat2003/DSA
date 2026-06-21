#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> nums = {2, 5, 7, 9};
    int target = 160;

    vector<int> ans;
    int i = 0;
    int j = nums.size() - 1;

    while (i < j)
    {
        int pairsum = nums[i] + nums[j];

        if (pairsum > target)
        {
            j--;
        }
        else if (pairsum < target)
        {
            i++;
        }
        else
        {
            ans.push_back(nums[i]);  // store values (better)
            ans.push_back(nums[j]);
            break; 
        }
    }

    if (!ans.empty())
    {
        cout << "Pair: ";
        for (auto var : ans)
        {
            cout << var << " ";
        }
    }
    else
    {
        cout << "No pair found";
    }

    cout << endl;
}