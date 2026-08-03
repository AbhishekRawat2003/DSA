#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Solution
{
public:
    bool canConstruct(string ransomNote, string magazine)
    {
        vector<int> str(26, 0);
        for (char c : magazine)
        {
            str[c - 'a']++;
        }

        for(auto val: ransomNote){
            str[val - 'a']--;         
            if (str[val - 'a'] < 0) {  
                return false;
            }

        }
        return true;
    }
};

int main()
{
    string ransomeNote = "a";
    string magazine = "b";
    Solution s;
    cout << s.canConstruct(ransomeNote, magazine);
    return 0;
}