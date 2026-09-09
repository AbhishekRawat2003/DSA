#include <iostream>
using namespace std;
// 1<=n<=1e+15
class Solution {
public:
    long long countCommas(long long n) {
        long long count = 0;
        long long start = 1000;
        long long commas = 1;

        while (start <= n) {
            long long end = min(n, start * 1000 - 1);
            count += (end - start + 1) * commas;
            cout<<"End: "<<end <<" Count: "<<count <<endl;
            start *= 1000;
            commas++;
            cout<<"Start: "<<start <<" commas: "<<commas<<endl;
        }

        return count;
    }
};

int main()
{
    long long n = 1004590;
    // long long n=954895548995489;
    Solution s;
    cout << s.countCommas(n) << endl;
    return 0;
}