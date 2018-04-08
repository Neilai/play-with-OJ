#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int integerBreak(int n) {
		 int dp[n+1]={0};
		 dp[1]=1;
		 for(int i=2;i<=n;i++)
		 	for(int j=i-1;j>=1;j--){
		 		dp[i]=max(dp[i],dp[j]*(i-j));
		 		dp[i]=max(dp[i],j*(i-j));
		 	}
		 return dp[n];
	}
};

int main(){
	Solution s;
	cout<<s.integerBreak(10);
}