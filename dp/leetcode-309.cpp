#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        if (prices.size() <= 1)
            return 0;
        int n = prices.size();
        vector<int> dp(n + 3, 0);
        dp[n - 2] = max(0, prices[n - 1] - prices[n - 2]);
        for (int i = n - 3; i >= 0; i--)
            for (int j = i + 1; j <= n - 1; j++)
                dp[i] = max(prices[j] - prices[i] + dp[j + 2], max(dp[i + 1], dp[i]));
        return dp[0];
    }
};
int main(int argc, char const *argv[])
{
    Solution s;
    int arr[5] = {1, 2, 3, 0, 2};
    vector<int> a(arr, arr + 5);
    cout << s.maxProfit(a);
    return 0;
}

// class Solution {
// public:
// 	int maxProfit(vector<int>& prices){
// 		if (prices.size() <= 1) return 0;
// 		vector<int> s0(prices.size(), 0);
// 		vector<int> s1(prices.size(), 0);
// 		vector<int> s2(prices.size(), 0);
// 		s1[0] = -prices[0];
// 		s0[0] = 0;
// 		s2[0] = INT_MIN;
// 		for (int i = 1; i < prices.size(); i++) {
// 			s0[i] = max(s0[i - 1], s2[i - 1]);
// 			s1[i] = max(s1[i - 1], s0[i - 1] - prices[i]);
// 			s2[i] = s1[i - 1] + prices[i];
// 		}
// 		return max(s0[prices.size() - 1], s2[prices.size() - 1]);
// 	}
// };