#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
using namespace std;

// dp[i][j]: coins obtained from bursting all the balloons between index i and j (not including i or j)
// dp[i][j] = max(nums[i] * nums[k] * nums[j] + dp[i][k] + dp[k][j]) (k in (i+1,j))
// If k is the index of the last balloon burst in (i, j), the coins that burst will get are nums[i] * nums[k] * nums[j], and to calculate dp[i][j], we also need to add the coins obtained from bursting balloons between i and k, and between k and j, i.e., dp[i][k] and dp[k][j]
//关键滑动游标k  （i，j）
class Solution
{
public:
    int search(vector<int> &nums, vector<vector<int>> &memo, int i, int j)
    {
        if ( i>=j)
            return 0;      
        if (memo[i][j]>0)
            return memo[i][j];
        for (int k = i + 1; k < j; k++)
        {
            memo[i][j] = max(memo[i][j], nums[i] * nums[k] * nums[j] + search(nums, memo, i, k) + search(nums, memo, k, j));
          
        }
        return memo[i][j];
    }
    int maxCoins(vector<int> &nums)
    {
        int n = nums.size();
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        vector<vector<int>> memo(nums.size(), vector<int>(nums.size(), 0));
        return search(nums, memo, 0, n + 1);
    }
};