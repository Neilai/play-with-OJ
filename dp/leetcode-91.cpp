#include<iostream>
#include<vector>
#include<string>
#include<cstdlib>
// 这题 题意不清 太坑了
using namespace std;
class Solution {
public:
    int numDecodings(string s) {
    	if(!s.size()||s[0]=='0')
    		return 0;
    	int n=s.size();
    	int dp[n];
    	int pos=n;
    	for(int i=0;i<n;i++){
    		dp[i]=1;
    	}
    	for(int i=1;i<pos;i++){    		
    		int tmp=(int(s[i-1])-48)*10+int(s[i])-48;	
    		if(tmp>=1&&tmp<=26)
    			if(i-2>=0&&s[i]!='0')
    				dp[i]=max(dp[i],dp[i-2]+2);
    			else if (i-2>=0&&s[i]=='0')
    				dp[i]=max(dp[i],dp[i-2]+1);
    			else if (s[i]!='0')
    				dp[i]=2;
    			else
    				dp[i]=1;
    		else if(s[i]=='0'){
    			pos=i;break;
    		}        		
    		dp[i]=max(dp[i],dp[i-1]);
    	}
    	return dp[pos-1];
    }
};
    
int main(){
	Solution s;
	// string s="12";
	// cout<<int(s[0]);
	// cout<<atoi("1");
	cout<<s.numDecodings("100");
}