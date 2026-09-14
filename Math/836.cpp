#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    bool isRectangleOverlap(vector<int> &rec1, vector<int> &rec2)
    {
        if (rec1[2] > rec2[0] && rec1[3] > rec2[1])
        {
            return true;
        }
        else if (rec1[2] < rec2[0] && rec1[3] < rec2[1] && rec1[2] < 0 && rec2[0] < 0 && rec1[3] < 0 && rec2[1] < 0)
        {
            return true;
        }
        return false;
    }
};
int main()
{
    vector<int> rec1 = {5,15,8,18};
    vector<int> rec2 = {0,3,7,9};
    Solution s;
    cout << s.isRectangleOverlap(rec1, rec2) << endl;
    return 0;
}