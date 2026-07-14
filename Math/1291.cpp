#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> result;
        
        for (int start = 1; start <= 8; ++start) {
            int num = start;
            
            for (int next = start + 1; next <= 9; ++next) {
                num = num * 10 + next;
                if (num >= low && num <= high) {
                    result.push_back(num);
                }
            }
        }
        
        sort(result.begin(), result.end());
        
        return result;
    }
};

int main() {
    int n1 = 100;
    int n2 = 300;
    Solution s;
    vector<int> res = s.sequentialDigits(n1, n2);
    
    cout << "Result: ";
    for (int val : res) {
        cout << val << " ";
    }
    cout << endl;
    
    return 0;
}   