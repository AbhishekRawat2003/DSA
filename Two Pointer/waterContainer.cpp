// [1,8,6,2,5,4,8,3,7]
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> container = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    // TLE
    int maxVol = 0;
    // int len = container.size();
    // for (int i = 0; i < len; i++)
    // {
    // for (int j = i + 1; j < len; j++)
    // {
    // int he = min(container[i], container[j]);
    // maxVol = max(maxVol, he * (j-i));
    // }
    // }
    // cout << maxVol << endl;
    int i = 0;
    int j = container.size() - 1;
    while (i < j)
    {
        int w = j - i;
        int length = min(container[i], container[j]);
        maxVol = max(w * length, maxVol);
        if (container[i] < container[j])
            i++;
        else
            j--;
    }
    cout << maxVol << endl;
    return 0;
}