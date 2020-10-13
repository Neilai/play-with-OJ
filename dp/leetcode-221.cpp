#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
using namespace std;

class Solution
{
public:
    int maximalSquare(vector<vector<char>> &matrix)
    {
        int m = matrix.size();
        if (!m)
            return 0;
        int n = matrix[0].size();
        int maxNum = 0;
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for (int i = 0; i < n; i++)
        {
            if (matrix[0][i] == '1')
            {
                dp[0][i] = 1;
                maxNum = 1;
            }
        }
        for (int j = 0; j < m; j++)
        {
            if (matrix[j][0] == '1')
            {
                maxNum = 1;
                dp[j][0] = 1;
            }
        }
        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                if (matrix[i][j] == '1')
                {
                    dp[i][j] = min(dp[i - 1][j], min(dp[i - 1][j - 1], dp[i][j - 1])) + 1;
                    if (dp[i][j] > maxNum)
                        maxNum = dp[i][j];
                }
            }
        }
        return maxNum * maxNum;
    }
};
int main(int argc, const char **argv)
{
    cout << max(1, 2);
}