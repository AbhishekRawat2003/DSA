//  remove all occurence
#include <iostream>
#include <vector>
#include <unordered_map>
#include <climits>

using namespace std;
string removeAllOccurence(string str, string part)
{
    // Remove all occurrences of part
    //==> OPTIMAL SOLUTION
    // while (str.find(part) != string::npos)
    // {
    //     str.erase(str.find(part), part.length());
    // }

    // return str;

    while (str.length() > part.length() && part.length() != 0 && str.find(part) < str.length())
    {
        cout << "str.find(part): " << str.find(part) << endl;
        cout << "part.length(): " << part.length() << endl;
        str.erase(str.find(part), part.length());
    }
    return str;
}

int main()
{
    string str = "daabcbaabcbc";
    string part = "abc";

    cout << "lenght of str: " << str.length() << endl;
    cout << "lenght of part: " << part.length() << endl;
    string result = removeAllOccurence(str, part);
    cout << "Final string after remove all occurence: " << result << endl;
    return 0;
}