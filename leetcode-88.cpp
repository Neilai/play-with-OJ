#include<vector>
#include<iostream>
using namespace std;
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int p=0,q=0;
        vector<int> result;
        int i=0;
        for(;i<m+n;i++){
        	if(p<m&&q<n){
        		if(nums1[p]<nums2[q])
        			result.push_back(nums1[p++]);
        		else
        			result.push_back(nums2[q++]);
        	}
        	else if(p<m){
        		while(p!=m){
        			i++;
        			result.push_back(nums1[p++]);
        		}
        	}
        	else{
        		while(q!=n){
        			i++;
        			result.push_back(nums2[q++]);
        		};
        	}	
        }
        nums1.erase(nums1.begin(),nums1.begin()+nums1.size());
        for(int i=0;i<m+n;i++){
        	nums1.push_back(result[i]);
        }
        for(int i=0;i<nums1.size();i++)
        	cout<<nums1[i];
    }
};
int main(){
	Solution s;
	std::vector<int> nums1,nums2;
	for(int i=1;i<10;i+=2)
		nums1.push_back(i),nums2.push_back(i+1);
	s.merge(nums1,nums1.size(),nums2,nums2.size());
}