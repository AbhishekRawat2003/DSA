#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Solution
{
public:
bool isValid(string s) {
        vector<char> stack;

        for (char ch : s) {
            if (ch == '(' || ch == '{' || ch == '[') {
                stack.push_back(ch);
            } else {
                if (stack.empty()) {
                    return false;
                }

                char top = stack.back();

                if ((ch == ')' && top == '(') ||
                    (ch == '}' && top == '{') ||
                    (ch == ']' && top == '[')) {
                    stack.pop_back();
                } else {
                    return false;
                }
            }
        }

        return stack.empty();
    }
};

int main()
{
    string str = "{}[](";
    Solution s;

    cout << s.isValid(str);
}