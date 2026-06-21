// Allocate Minimum Pages

// Given an array arr[] of integers,
// where
// Each element arr[i] represents the number of pages in the i-th book.
// Integer k representing the number of students.
// The task is to allocate books to each student such that:

//      Each student receives atleast one book.
//      Each student is assigned a contiguous sequence of books.
//      No book is assigned to more than one student.
//      All books must be allocated.

// The objective is to minimize the maximum number of pages assigned to any student. In other words, out of all possible allocations, find the arrangement where the student who receives the most pages still has the smallest possible maximum.

// Note: If it is not possible to allocate books to all students, return -1.

// Examples:
// Input: arr[] = [12, 34, 67, 90], k = 2
// Output: 113
// Explanation: Allocation can be done in following ways:
// => [12] and [34, 67, 90] Maximum Pages = 191
// => [12, 34] and [67, 90] Maximum Pages = 157
// => [12, 34, 67] and [90] Maximum Pages = 113.
// The third combination has the minimum pages assigned to a student which is 113.

#include <iostream>
#include <vector>
using namespace std;

// typedef long long ll;
bool isValid(vector<int> nums, int maximumAllowedPages, int m)
{
    int student = 1;
    int pages = 0;

    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] > maximumAllowedPages)
        {
            return false;
        }
        else if (pages + nums[i] <= maximumAllowedPages)
        {
            pages += nums[i];
        }
        else
        {
            student++;
            pages = nums[i];
        }
    }
    return student > m ? false : true;
}
int binarySearch(vector<int> nums, int student)
{
    int start = 0;
    for (int i = 1; i < nums.size(); i++)
    {
        if (nums[i] > start)
        {
            start = nums[i];
        }
    }
    int end = 0;
    for (auto var : nums)
    {
        end += var;
    }
    cout << "Range of Binary Search: " << endl;
    cout << "Start(Min.) " << start << " || " << "End(Max.) " << end << endl;
    int ans = -1;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        cout << "Mid: " << mid << endl;

        if (isValid(nums, mid, student))
        {
            ans = mid;
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
    return ans;
}
int main()
{
    vector<int> nums = {12, 34, 67, 90};
    int m = 2;

    int result = binarySearch(nums, m);
    cout << "Maximum Pages of Minimum gap between Students : " << result << endl;
    return 0;
}