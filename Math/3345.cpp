#include <iostream>
using namespace std;

class Solution
{
public:
    int smallestNumber(int n, int t)
    {
        for (int i = n; i <= 100; i++)
        {
            int num = i;
            int mul = 1;

            while (num != 0)
            {
                int rem = num % 10;
                mul *= rem;
                num /= 10;
            }

            if (mul % t == 0)
            {
                return i;
            }
        }

        return -1;
    }
};

int main()
{
    int n = 15;
    int t = 3;

    Solution s;
    cout << s.smallestNumber(n, t) << endl;

    return 0;
}