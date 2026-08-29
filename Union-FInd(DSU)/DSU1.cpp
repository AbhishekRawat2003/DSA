#include <iostream>
#include <vector>

using namespace std;

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

    bool unite(int x, int y)
    {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX == rootY)
        {
            return false;
        }

        // Union by rank
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

        return true;
    }

    bool connected(int x, int y)
    {
        return find(x) == find(y);
    }
};

int main()
{
    vector<char> nums = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'};
    int n = nums.size();

    // Create Union-Find with n elements

    cout << "--- Performing Unions ---" << endl;

    uf.unite(0, 1);
    cout << "Unite 'a' and 'b'" << endl;

    uf.unite(2, 3);
    cout << "Unite 'c' and 'd'" << endl;

    uf.unite(1, 2);
    cout << "Unite 'b' and 'c' -> Connects {a,b} and {c,d}" << endl;

    uf.unite(4, 5);
    cout << "Unite 'e' and 'f'" << endl;

    cout << "\n--- Checking Connectivity ---" << endl;

    cout << "Are 'a' and 'd' connected? "
         << (uf.connected(0, 3) ? "Yes" : "No") << endl;

    cout << "Are 'a' and 'e' connected? "
         << (uf.connected(0, 4) ? "Yes" : "No") << endl;

    cout << "Are 'e' and 'f' connected? "
         << (uf.connected(4, 5) ? "Yes" : "No") << endl;

    return 0;
}
