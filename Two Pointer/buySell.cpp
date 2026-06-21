#include <iostream>
using namespace std;
#include <vector>

int main()
{
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    int maxProfit = 0;
    int buy = prices[0];
    // for(int i=1; i<prices.size(); i++){
    //     if(prices[i] > prices[i-1]){
    //         maxProfit += prices[i] - prices[i-1];
    //     }
    // }
    // cout << "Maximum profit: " << maxProfit << endl;
    // return 0;
    // for (int i = 0; i < prices.size(); i++)
    // {
    //     int buy = prices[i];

    //     for (int j = i; j < prices.size(); j++)
    //     {
    //         maxProfit = max(maxProfit, prices[j] - buy);
    //     }
    // }
    // cout << "Maximum profit: " << maxProfit << endl;
    for (auto val : prices)
    {
        buy = min(buy, val);
        maxProfit = max(maxProfit, val-buy);
    }
    cout << maxProfit << endl;
}