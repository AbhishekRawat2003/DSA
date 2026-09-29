// solid pyramid (equilateral triangle)

#include <iostream>
using namespace std;

int main()
{
    int n = 4;

    for (int i = 0; i < n; i++)
    {
        // space
        for (int j = 0; j < n - i; j++)
        {
            cout << " ";
        }
        // Star
        for (int j = 0; j<2 * i + 1; j++)
        {
            cout << "*";
        }
        cout<<endl;
    }
}