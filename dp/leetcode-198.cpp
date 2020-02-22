#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
using namespace std;

class Solution
{
public:
    int rob(vector<int> &nums)
    {
        if (nums.empty())
            return 0;
        int n = nums.size();
        vector<int> dp(n, -1);
        dp[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--)
            dp[i] = max(dp[i + 1], i + 2 > n - 1 ? nums[i] : dp[i + 2] + nums[i]);
        return dp[0];
    }
};

int main(int argc, char const *argv[])
{
    /* code */
    int arr[5] = {2, 7, 9, 3, 1};
    vector<int> x(arr, arr + 5);
    Solution s;
    cout << s.rob(x);
    return 0;
}
