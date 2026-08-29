#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <cmath> // For abs

using namespace std;

class Solution
{
    class unionFind
    {
    private:
        vector<int> parent;
        vector<int> rank;

    public:

        unionFind(int n) 
        {
            parent.resize(n);
            rank.resize(n, 0);

            for (int i = 0; i < n; i++)
            {
                parent[i] = i;
            }
        }

        int find(int x)
        {
            if (parent[x] != x)
            {
                parent[x] = find(parent[x]); 
            }
            return parent[x];
        }

        // FIX 2: Ensure return type matches implementation
        bool unite(int x, int y)
        {
            int rootX = find(x);
            int rootY = find(y);

            cout<<"rootx & rootY = " <<rootX << " " <<rootY <<endl;
            if (rootX == rootY)
                return false; 

            if (rank[rootX] < rank[rootY])
            {
                parent[rootX] = rootY;
            }
            else if (rank[rootX] > rank[rootY])
            {
                parent[rootY] = rootX;
            }
            else
            {
                parent[rootY] = rootX;
                rank[rootX]++;
            }
            cout<< "Parent = "; 
            for(auto num: parent){
                cout<< num << " ";
            }
            cout<< "\nRank = ";
            for(auto num : rank){
                cout<< num <<" ";
            }
            return true;
        }
    };

public:
    vector<int> lexicographicallySmallestArray(vector<int> &nums, int limit)
    {
        int n = nums.size();
        vector<pair<int, int>> arr;
        for (int i = 0; i < n; i++)
        {
            arr.push_back({nums[i], i});
        }
        

        sort(arr.begin(), arr.end());
        
        unionFind uf(n);

        for (int i = 1; i < n; i++)
        {
            if (arr[i].first - arr[i - 1].first <= limit) 
            {

                cout<< "\nUnite : arr[i-1] and arr[i] = "<< arr[i - 1].second << " " <<arr[i].second <<endl;
                uf.unite(arr[i - 1].second, arr[i].second);
            }
        }


        unordered_map<int, vector<int>> grp;
        for (int i = 0; i < n; i++)
        {
            
            grp[uf.find(i)].push_back(i);
        }


        for (auto &[root, indices] : grp)
        {
            vector<int> values;
            for (int index : indices)
            {
                values.push_back(nums[index]);
            } 
            

            sort(indices.begin(), indices.end());

            sort(values.begin(), values.end());


            for (int i = 0; i <indices.size(); i++)
            {
                nums[indices[i]] = values[i];
            }
        }

        return nums;
    }
};

int main()
{
    vector<int> nums = {1, 5, 3, 9, 8};
    int limit = 2;
    Solution s;

    vector<int> result = s.lexicographicallySmallestArray(nums, limit);

    cout << "\nResult: ";
    for (auto it : result)
    {
        cout << it << " ";
    }
    cout << endl;

    return 0;
}