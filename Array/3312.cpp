#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;

typedef long long ll;

class Solution
{
public:
    vector<int> gcdValues(vector<int> &nums, vector<ll> &queries)
    {
        // find maxElement
        int mx = *max_element(nums.begin(), nums.end());
        cout << "==================================\n";
        cout << "STEP 1: Max element in nums = " << mx << "\n";

        // find Frequency
        vector<int> freq(mx + 1, 0);
        for (auto val : nums)
        {
            freq[val]++;
        }
        cout << "\nSTEP 2: Frequency array (freq[v] = how many times v appears)\n";
        for (int v = 1; v <= mx; v++)
            cout << "  freq[" << v << "] = " << freq[v] << "\n";

        // count number divisible by each divisor d
        vector<ll> cnt(mx + 1, 0);
        for (int d = 1; d <= mx; d++)
        {
            for (int multiple = d; multiple <= mx; multiple += d)
            {
                cnt[d] += freq[multiple];
            }
        }
        cout << "\nSTEP 3: cnt[d] = count of elements divisible by d\n";
        for (int d = 1; d <= mx; d++)
            cout << "  cnt[" << d << "] = " << cnt[d] << "\n";

        // Count pairs with exact gcd = d
        vector<ll> exact(mx + 1, 0);
        for (int d = mx; d >= 1; d--)
        {
            exact[d] = cnt[d] * (cnt[d] - 1) / 2;
            cout << "\n  d = " << d << " -> initial pairs (C(cnt[d],2)) = " << exact[d];

            for (int multiple = 2 * d; multiple <= mx; multiple += d)
            {
                exact[d] -= exact[multiple];
                cout << "\n    subtracting exact[" << multiple << "] (=" << exact[multiple]
                     << ") -> exact[" << d << "] now = " << exact[d];
            }
            cout << "\n  FINAL exact[" << d << "] = " << exact[d] << "\n";
        }

        cout << "\nSTEP 4: exact[] array (pairs with gcd exactly d)\n";
        for (int d = 1; d <= mx; d++)
            cout << "  exact[" << d << "] = " << exact[d] << "\n";

        // Prefix cumulative counts
        vector<ll> prefix(mx + 1, 0);

        for (int d = 1; d <= mx; d++)
        {
            prefix[d] = prefix[d - 1] + exact[d];
        }
        cout << "\nSTEP 5: prefix[] array (cumulative pair counts up to gcd d)\n";
        for (int d = 1; d <= mx; d++)
            cout << "  prefix[" << d << "] = " << prefix[d] << "\n";

        // Answer queries
        vector<int> ans;
        cout << "\nSTEP 6: Answering queries via binary search on prefix[]\n";
        for (ll q : queries)
        {
            int gcdValue = upper_bound(prefix.begin(), prefix.end(), q) - prefix.begin();
            cout << "  query q = " << q
                 << " -> smallest d with prefix[d] > q is d = " << gcdValue << "\n";
            ans.push_back(gcdValue);
        }

        return ans;
    }
};

int main()
{
    // vector<int> nums = {2, 3, 4};
    // vector<ll> queries = {0, 2, 2};

    vector<int> nums = {4, 4, 2, 1};
    vector<ll> queries = {5, 3, 1, 0};

    Solution s;
    vector<int> ans = s.gcdValues(nums, queries);

    cout << "\n==================================\n";
    cout << "FINAL ANSWER - sorted GCD Pair Queries: ";
    for (int x : ans)
    {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}