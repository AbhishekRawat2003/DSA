#include <iostream>
#include <vector>

using namespace std;

// class Solution
// {
//     // brute force
// public:
//     int trap(vector<int> &height)
//     {
//         int n = height.size();

//         if (n == 0)
//             return 0;

//         int h1 = 0;
//         int h2 = h1 + 1;
//         int trap = 0;

//         while (h1 < n - 1)
//         {
//             cout << "\nCurrent h1 = " << h1
//                  << " height = " << height[h1] << endl;

//             // Case 1: Find taller/equal wall
//             while (h2 < n && height[h2] < height[h1])
//             {
//                 h2++;
//             }

//             // Case 2: No taller wall found
//             if (h2 == n)
//             {
//                 cout << "No bigger wall found. Searching maximum wall..." << endl;

//                 int maxHeight = 0;
//                 int index = -1;

//                 for (int i = h1 + 1; i < n; i++)
//                 {
//                     if (height[i] > maxHeight)
//                     {
//                         maxHeight = height[i];
//                         index = i;
//                     }
//                 }

//                 // Case 3: No wall on right
//                 if (index == -1)
//                 {
//                     break;
//                 }

//                 h2 = index;

//                 cout << "Maximum right wall found at index "
//                      << h2 << " height = "
//                      << height[h2] << endl;
//             }

//             int waterLevel = min(height[h1], height[h2]);

//             cout << "h2 = " << h2
//                  << " height = " << height[h2]
//                  << endl;

//             // Calculate water
//             for (int i = h1 + 1; i < h2; i++)
//             {
//                 if (waterLevel > height[i])
//                 {
//                     int add = waterLevel - height[i];

//                     cout << "Index " << i
//                          << " add water = "
//                          << add << endl;

//                     trap += add;
//                 }
//             }

//             cout << "Total water = " << trap << endl;

//             // Move left wall
//             h1 = h2;
//             h2 = h1 + 1;
//         }

//         return trap;
//     }
// };

// class Solution {
// public:
//     int trap(vector<int>& height) {

//         int n = height.size();
//         int water = 0;

//         for(int i=0;i<n;i++)
//         {
//             int leftMax = 0;
//             int rightMax = 0;

//             // find left maximum
//             for(int j=0;j<=i;j++)
//             {
//                 leftMax = max(leftMax,height[j]);
//             }

//             // find right maximum
//             for(int j=i;j<n;j++)
//             {
//                 rightMax = max(rightMax,height[j]);
//             }

//             water += min(leftMax,rightMax)-height[i];
//         }

//         return water;
//     }
// };

//=========================== DP =========================
class Solution
{
public:
    int trap(vector<int> &heights)
    {
        int n = heights.size();
        vector<int> left(n);
        vector<int> right(n);
        left[0] = heights[0];

        for (int i = 1; i < n; i++)
        {
            left[i] = max(left[i - 1], heights[i]);
        }

        right[n - 1] = heights[n - 1];

        for (int i = n - 2; i >= 0; i--)
        {
            right[i] = max(right[i + 1], heights[i]);
        }
        cout << "Left heights: ";
        for (auto val : left)
        {
            cout << val << " ";
        }

        cout << endl
             << "Right heights: ";
        for (auto val : right)
        {
            cout << val << " ";
        }
        cout << endl;
        int water = 0;

        for (int i = 0; i < n; i++)
        {
            water += min(left[i], right[i]) - heights[i];
        }

        return water;
    }
};

int main()
{
    // vector<int> height = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    vector<int> height = {4, 2, 0, 3, 2, 5};

    Solution s;

    cout << "\nFinal Answer = "
         << s.trap(height)
         << endl;

    return 0;
}