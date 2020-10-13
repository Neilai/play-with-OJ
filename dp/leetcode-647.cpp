#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
using namespace std;
class Solution
{
public:
    int countSubstrings(string s)
    {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int i = n - 1; i >= 0; i--)
        {
            dp[i][i] = 1;
            for (int j = i + 1; j < n; j++)
            {
                dp[i][j] = s[i] == s[j] && (j - i == 1 || dp[i + 1][j - 1]);
            }
        }
        int cnt = 0;
        for (int i = 0; i < dp.size(); i++)
            for (int j = 0; j < dp[i].size(); j++)
                if (dp[i][j])
                    cnt++;
        return cnt;
    }
};