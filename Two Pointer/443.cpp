#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
    int compress(vector<char> &chars)
    {
        int n = chars.size();
        int idx = 0;
        int i = 0;

        while (i < n)
        {
            // assign character
            char curr_char = chars[i];
            int count = 0;
            while (i < n && curr_char == chars[i])
            {
                count++;
                i++;
            }
            chars[idx] = curr_char;
            idx++;
            if (count > 1)
            {
                string count_str = to_string(count);
                for (char &ch : count_str)
                {
                    chars[idx] = ch;
                    idx++;
                }
            }
        }
        return idx;
    }
};
int main()
{
    vector<char> str = {'a', 'a', 'b', 'b', 'c', 'c', 'c'};
    Solution s;
    cout << s.compress(str);
    cout << endl;
    return 0;
}