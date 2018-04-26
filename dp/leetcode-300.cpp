#include<vector>
#include<string>
#include<cstdlib>
using namespace std;
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
    	int n=nums.size();
    	if(!n)
    		return 0;
    	int dp[n]={0};
    	for(int i=0;i<n;i++)
    		dp[i]=1;
    	dp[0]=1;
    	for(int i=1;i<n;i++)
    		for(int j=0;j<i;j++)z
    			if(nums[i]>nums[j])
    				dp[i]=max(dp[i],dp[j]+1);
    	int res=dp[0];
    	for(int i=1;i<n;i++)
    		if(res<dp[i])
    			res=dp[i];
    	return res;
    }
};
int main(){
	// Solution s;
	// vector x;
	// [10, 9, 2, 5, 3, 7, 101, 18]
	// s.lengthOfLIS();
}