#include <iostream>
using namespace std;

bool isAlphaNumeric(char ch)
{
    // a-z
    if (ch >= 'a' && ch <= 'z')
        return true;

    // A-Z
    if (ch >= 'A' && ch <= 'Z')
        return true;

    // 0-9
    if (ch >= '0' && ch <= '9')
        return true;

    return false;
}

char toLowerCase(char ch)
{
    if (ch >= 'A' && ch <= 'Z')
    {
        return ch + 32;
    }

    return ch;
}

bool isPalindrome(string s)
{
    int st = 0;
    int end = s.size() - 1;

    while (st < end)
    {
        // Skip special characters
        while (st < end && !isAlphaNumeric(s[st]))
        {
            st++;
        }

        while (st < end && !isAlphaNumeric(s[end]))
        {
            end--;
        }

        // Compare lowercase characters
        if (toLowerCase(s[st]) != toLowerCase(s[end]))
        {
            return false;
        }

        st++;
        end--;
    }

    return true;
}

int main()
{
    string str1 = "A man, a plan, a canal: Panama";

    bool result = isPalindrome(str1);

    if (result)
    {
        cout << "== Palindrome ==" << endl;
    }
    else
    {
        cout << "== Not Palindrome ==" << endl;
    }

    return 0;
}