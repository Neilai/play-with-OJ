#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
using namespace std;
class Solution
{
public:
    int coinChange(vector<int> &coins, int amount)
    {
        int n = coins.size();
        vector<int> memo(amount + 1, 0x3f3f3f3f);
        //这题关键是初始化
        for (int i = 0; i <= amount; i++)
        {
            if (i % coins[0] == 0)
                memo[i] = i / coins[0];
        }
        for (int i = 1; i < n; i++)
        {
            for (int j = coins[i]; j <= amount; j++)
            {
                memo[j] = min(memo[j], memo[j - coins[i]] + 1);
            }
        }
        return memo[amount] == 0x3f3f3f3f ? -1 : memo[amount];
    }
};