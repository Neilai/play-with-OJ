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
    }
};

// 改进  双指针这样写很不优雅，可以把两个while给去掉
// 另外 可以不用另外开辟一个变量，可以把nums1复制一份放到后面


class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {

        assert(nums1.size() == m + n && nums2.size() == n);

        for(int i = n + m - 1 ; i >= n ; i -- )
            nums1[i] = nums1[i - n];

        int i = n;  // pointer for nums1 [n, n+m)
        int j = 0;  // pointer for nums2 [0, n)
        int k = 0;  // pointer merged nums1 [0, n+m)
        while( k < n + m ){
            if( i >= n+m )
                nums1[k++] = nums2[j++];
            else if( j >= n )
                nums1[k++] = nums1[i++];
            else if( nums1[i] < nums2[j] )
                nums1[k++] = nums1[i++];
            else
                nums1[k++] = nums2[j++];
        }
    }
};