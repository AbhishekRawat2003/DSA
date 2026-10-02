#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
    void backtrack(string curr, int opened, int closed, int n, vector<string> &result)
    {
        if (opened == n && closed == n)
        {
            result.push_back(curr);
            return;
        }
        if (opened < n)
        {
            backtrack(curr + "(", opened + 1, closed, n, result);
        }
        if (closed < opened)
        {
            backtrack(curr + ")", opened, closed + 1, n, result);
        }
    }
    vector<string> generateParenthesis(int n)
    {
        vector<string> result;
        backtrack("", 0, 0, n, result);
        return result;
    }
};

int main()
{
    int n = 3;
    Solution s;
    vector<string> result = s.generateParenthesis(n);
    cout<< "[ ";
    for (auto str : result)
    {
        cout <<"'"<< str << "'"<< " ";
    }
    cout <<" ]"<< endl;
    return 0;
}