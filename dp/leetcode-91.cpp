#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>

// 这题 题意要考虑0, 太坑了

using namespace std;
class Solution
{
public:
	vector<int> memo;
	int findWay(string s, int index)
	{
		if (memo[index] != -1)
			return memo[index];
		if (s[index] == '0')
			return 0;
		if (index >= s.size() - 1)
			return 1;
		if (index <= s.size() - 2 && stoi(s.substr(index, 2)) <= 26)
			return memo[index] = findWay(s, index + 2) + findWay(s, index + 1);
		else
			return memo[index] = findWay(s, index + 1);
	}
	int numDecodings(string s)
	{
		memo = vector<int>(s.size() + 1, -1);
		return findWay(s, 0);
	}
	int numDecodings_dp(string s)
	{
		int n = s.size();
		vector<int> dp(n + 1);
		dp[n] = 1;
		for (int i = n - 1; i >= 0; i--)
		{
			if (s[i] == '0')
				dp[i] = 0;
			else
			{
				dp[i] = dp[i + 1];
				if (i < n - 1 && (s[i] == '1' || s[i] == '2' && s[i + 1] < '7'))
					dp[i] += dp[i + 2];
			}
		}
		return s.empty() ? 0 : dp[0];
	}
};

int main()
{
	Solution s;
	string str = "100";
	cout << s.numDecodings(str);
}

