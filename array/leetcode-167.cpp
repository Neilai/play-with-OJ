#include<vector>
#include<iostream>
#include<cctype>
using namespace std;
class Solution {
public:
	int search(vector<int>& numbers,int l,int r,int target){
		if(l>r) return -1;
		int middle=(l+r)/2;
		if(numbers[middle]==target)
			return middle;
		else if(numbers[middle]>target)
			return search(numbers,l,middle-1, target);
		else 
			return search(numbers,middle+1,r, target);
		return -1;
	}
    vector<int> twoSum(vector<int>& numbers, int target) {
    	for (int i = 0; i < numbers.size(); ++i) {
    	    	int another=search(numbers,i+1,numbers.size()-1,target-numbers[i]);
    	    	if(another!=-1){
    	    		int res[2]={i+1,another+1};
    	    		return vector<int>(res,res+2);
    	    	}
    	    }    
    }
};
// int main(){
// 	Solution s;
// 	int numbers[4] = {2,7,11,15};
// 	int target = 9;
// 	vector<int> x=vector<int> (numbers,numbers+4);
// 	s.twoSum(x,target);
// }