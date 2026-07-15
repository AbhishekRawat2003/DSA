#include <iostream>
#include<numeric>
using namespace std;
class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        // int oddSum=0;
        // int evenSum=0;
        // for(int i=0;i<n;i++){
        //     oddSum+=1;
        //     evenSum +=2;
        // }
        // return gcd(oddSum,evenSum);

      return gcd(n*n,n*(n+1));
    }
};

int main() {
    int n=1000;
    Solution s;
    cout<<s.gcdOfOddEvenSums(n);
    
    return 0;
}
