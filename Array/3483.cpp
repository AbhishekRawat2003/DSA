#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
class Solution
{
public:
    int totalNumbers(vector<int> &digits)
    {
        int n = digits.size();
        vector<int> mp(10, 0);
        for (auto digit : digits)
        {
            mp[digit]++;
        }
        int count = 0;
        for (int i = 1; i <= 9; i++)
        {
            if (mp[i] == 0)
                continue;
            mp[i]--;
            for (int j = 0; j <= 9; j++)
            {
                if (mp[j] == 0)
                    continue;
                mp[j]--;
                for (int k = 0; k <= 8; k += 2)
                {
                    if (mp[k] == 0)
                        continue;
                    mp[k]--;

                    int num = i * 100 + j * 10 + k;
                    if (num % 2 == 0)
                        count++;
                    mp[k]++;
                }
                mp[j]++;
            }
            mp[i]++;
        }
        return count;
    }
};

int main()
{
    vector<int> digits = {1, 2, 4, 3};
    Solution s;
    cout << s.totalNumbers(digits) << endl;
    return 0;
}