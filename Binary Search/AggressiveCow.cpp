// Aggresive Cow Problem
// Find minimus distance between  them is largest possible.
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool isPossible(vector<int>& stalls, int cows, int minDist)
{
    int countCows = 1;
    int lastPos = stalls[0];

    for (int i = 1; i < stalls.size(); i++)
    {
        if (stalls[i] - lastPos >= minDist)
        {
            countCows++;
            lastPos = stalls[i];
        }

        if (countCows == cows)
        {
            return true;
        }
    }

    return false;
}

int aggressiveCows(vector<int>& stalls, int cows)
{
    sort(stalls.begin(), stalls.end());

    int start = 1;
    int end = stalls[stalls.size() - 1] - stalls[0];

    int ans = 0;

    while (start <= end)
    {
        int mid = start + (end - start) / 2;

        if (isPossible(stalls, cows, mid))
        {
            ans = mid;
            start = mid + 1; // maximize distance
        }
        else
        {
            end = mid - 1;
        }
    }

    return ans;
}

int main()
{
    vector<int> stalls = {1, 2, 4, 8, 9};

    int cows = 3;

    int ans = aggressiveCows(stalls, cows);

    cout << "Largest minimum distance: " << ans << endl;

    return 0;
}