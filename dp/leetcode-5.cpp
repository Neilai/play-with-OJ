#include <string>
#include <vector>
using namespace std;
class Solution
{
public:
    // string longestPalindrome(string s)
    // {
    //     if (s.empty())
    //         return "";
    //     int n = s.size(), left = 0, len = 1;
    //     vector<vector<int>> dp(n, vector<int>(n, 0));
    //     for (int i = n - 1; i >= 0; i--)
    //     {
    //         dp[i][i] = 1;
    //         for (int j = i + 1; j < n; j++)
    //         {
    //             dp[i][j] = s[i] == s[j] && (j - i == 1 || dp[i + 1][j - 1]);
    //             if (dp[i][j ]&& len < j - i + 1)
    //             {
    //                 left = i;
    //                 len = j - i + 1;
    //             }
    //         }
    //     }

    //     return s.substr(left, len);
    // }
    string longestPalindrome(string s)
    {
    }
};