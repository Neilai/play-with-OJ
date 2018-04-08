#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int numSquares(int n) {
		int dp[n+1]={0};
		for(int i=1;i<=n;i++)
			dp[i]=i;
		dp[0]=0;
		for(int i=1;i<=n;i++)
			for(int j=1;i-j*j>=0;j++)
				dp[i]=min(dp[i-j*j]+1,dp[i]);
		return dp[n];        
    }
};

int main(){
	Solution s;
	cout<<s.numSquares(16);
}