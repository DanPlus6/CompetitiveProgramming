// 121.Best Time to Buy and Sell Stock
#include <bits/stdc++.h>
using namespace std;

constexpr int INF = 0x3F3F3F3F;


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int lowest = INF;
        int res = 0;

        int profit;
        for (int i = 0; i < prices.size(); i++) {
            if (prices[i] < lowest) {
                lowest = prices[i];
            } else {
                profit = prices[i] - lowest;
                if (profit > res) res = profit;
            }
            
        }

        return res;
    }
};
