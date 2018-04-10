#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
    	int n=nums.size();
    	if(!n)
    		return 0;
    	int up[n]={0};
    	int down[n]={0};
    	for(int i=0;i<n;i++){
    		up[i]=1;
    		down[i]=1;
    	}
    	for(int i=1;i<n;i++)
    		for(int j=0;j<i;j++){
    		    if(nums[i]>nums[j])
    					up[i]=max(up[i],down[j]+1);
    			else if(nums[i]<nums[j])
    					down[i]=max(down[i],up[j]+1);
    		}
    	int res1=up[0];
    	for(int i=1;i<n;i++)
    		if(res1<up[i])
    			res1=up[i];
    	int res2=down[0];
    	for(int i=1;i<n;i++)
    		if(res2<down[i])
    			res2=down[i];
    	return max(res1,res2);
    }
};
int main(){

}