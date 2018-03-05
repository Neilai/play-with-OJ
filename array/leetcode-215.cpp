#include<vector>
#include<ctime>
#include<cstdlib>
#include<iostream>
using namespace std;
class Solution {
public:
	int partition(vector<int>& arr,int l,int r){
		int lt=r, eq=l+1,gt=l+1;
		srand(time(NULL));
		swap(arr[l],arr[rand()%(r-l+1)+l]);
		while(eq<=lt){
			if(arr[eq]<arr[l]){
				swap(arr[lt],arr[eq]);
				lt--;
			}
			else if(arr[eq]>arr[l]){
				swap(arr[eq],arr[gt]);
				eq++;gt++;
			}
			else
				eq++;
		}	
		swap(arr[gt-1],arr[l]);
		return gt-1;
	}


    int findKthLargest(vector<int>& nums, int k) {
 			k=k-1;
 			int l=0;
 			int r=nums.size()-1;
 			int index=partition(nums,l,r);
 			while(index!=k){
 				if(index>k){
 					r=index-1;
 				}
 				else if(index<k){
 					l=index+1;
 				}
 				index=partition(nums,l,r);
 			}
 			// cout<<nums[index];
 			return nums[index];
    }
};

int main(){
	Solution s;
	std::vector<int> v;
	v.push_back(1),v.push_back(9),v.push_back(2),v.push_back(5),v.push_back(3),v.push_back(11);
	s.partition(v,0,v.size()-1);
	s.findKthLargest(v,5);
}