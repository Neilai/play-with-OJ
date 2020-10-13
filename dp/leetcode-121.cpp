#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) return 0;
        int num = 0;
        vector<int> dp(prices.size());
        dp[0] = 0;
        for (int i = 1; i < prices.size(); i++) {
            dp[i] = max(0, dp[i - 1] + prices[i] - prices[i - 1]);
            num = max(dp[i], num);
        }
        return num;
    };
};

// class Solution {
//    public:
//    int maxProfit(vector<int> &prices) {
//     int maxPro = 0;
//     int minPrice = INT_MAX;
//     for(int i = 0; i < prices.size(); i++){
//         minPrice = min(minPrice, prices[i]);
//         maxPro = max(maxPro, prices[i] - minPrice);
//     }
//     return maxPro;
// }
// };