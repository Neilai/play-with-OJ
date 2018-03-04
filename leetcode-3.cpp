#include<vector>
#include<ctime>
#include<cstdlib>
#include<iostream>
// 滑动窗口的经典应用
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int map[256]={0};
        int l=0,r=0;
        int res=0;
        while(r<s.size()){	
        	if(!map[int(s[r])]){
        		res=max(res,r-l+1);
        		map[int(s[r])]=1;
        		r++;
        	}
        	else {
        		map[int(s[l])]=0;
        		l++;
        	}
        }
        return res;
    }
};
int main(){
	Solution s;
	cout<<s.lengthOfLongestSubstring("");		
}