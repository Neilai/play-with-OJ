#include<vector>
#include<iostream>
#include<cctype>
#include <climits>
using namespace std;
//数组问题注意越界问题
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
    	    int l=0,r=-1;
    	    int res=nums.size()+1;
    	    int sum=0;
    	    while(l<nums.size()){
    	    	if(sum<s&&r+1<nums.size()){
    	    		r++;
    	    		sum+=nums[r];	
    	    	} else{
       	    		sum-=nums[l];
       	    		l++;
    	    	}
    	    	if(sum>=s)
    	    		res=min(res,r-l+1);
    	    }
    	    if(res==nums.size()+1)
    	    	return 0;
    	    else 
    	    	return res;
    }
};
int main(){
	 int nums[6] = {2,3,1,2,4,3};
	 // vector<int> x(nums,nums+6);
	 // Solution s;
	 // cout<<s.minSubArrayLen(7,x);
	 // cout<<INT_MAX<<endl;
}


// class Solution {
// public:
//     int minSubArrayLen(int s, vector<int>& nums) {
//         int l = 0, r = 0, n = nums.size(), sum = 0, len = INT_MAX;
//         while (r < n) {
//             sum += nums[r++];
//             while (sum >= s) {
//                 len = min(len, r - l);
//                 sum -= nums[l++];
//             }
//         }
//         return len == INT_MAX ? 0 : len;
//     }
// };