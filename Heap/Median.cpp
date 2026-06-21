#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
{
    vector<int> merged;

    // Merge arrays
    merged.insert(merged.end(), nums1.begin(), nums1.end());
    merged.insert(merged.end(), nums2.begin(), nums2.end());

    // Sort merged array
    sort(merged.begin(), merged.end());

    // Print merged array
    for (auto val : merged)
    {
        cout << val << " ";
    }

    cout << endl;

    int n = merged.size();

    // If odd size
    if (n % 2 != 0)
    {
        return merged[n / 2];
    }

    return (merged[n / 2] + merged[n / 2 - 1]) / 2.0;
}

int main()
{
    vector<int> nums1 = {1, 3,4};
    vector<int> nums2 = {2};

    double result = findMedianSortedArrays(nums1, nums2);

    cout << "Median = " << result << endl;

    return 0;
}