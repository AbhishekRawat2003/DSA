#include<iostream>
using namespace std;
// 1<=n<=100000
class Solution {
public:
    int countCommas(int n) {
        if (n < 1000) {
            return 0;
        }
        if (n < 1000000) {
            return n - 999;
        }

        return 0;
    }
};

int main(){
    int n=9458;
    Solution s;
    cout<<s.countCommas(n)<<endl;
    return 0;
}