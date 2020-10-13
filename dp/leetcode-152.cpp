#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {
        vector<int> dp(nums.size());
        int maxNum = nums[0];
        int minNum = nums[0];
        dp[0] = nums[0];
        for (int i = 1; i < dp.size(); i++)
        {
            dp[i] = max(nums[i], max(nums[i] * dp[i - 1], nums[i] * minNum));
            minNum = min(nums[i], min(nums[i] * dp[i - 1], nums[i] * minNum));
            if (dp[i] > maxNum)
                maxNum = dp[i];
        }
        return maxNum;
    }
};