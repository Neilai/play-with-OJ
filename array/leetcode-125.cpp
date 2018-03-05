#include<vector>
#include<iostream>
#include<cctype>
using namespace std;
class Solution {
public:
    bool isPalindrome(string s) {
    	int l=0, r=s.size()-1;
		int flag=1; 
    	while(l<r){
    		while(!isalnum(s[l])&&l<r)
    			l++;
    		while(!isalnum(s[r])&&l<r)
    			r--;
    		if(toupper(s[l])==toupper(s[r])){
    			l++;r--;
    		}
    		else{
    			flag=0;break;
    		}
    	}
        return flag;
    }
};
int main(){
	Solution s;
	string x="0P";
	cout<<s.isPalindrome(x);
	return 1;
}