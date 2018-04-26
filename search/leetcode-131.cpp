#include <iostream>
#include <string>
#include <vector>
#include <cassert>

using namespace std;
class Solution {
public:
	bool isPalindrome(string s){
		int len=s.size();
		for(int i=0;i<len/2;i++)
			if(s[i]!=s[len-i-1])
				return false;
		return true;
	}
	vector<vector<string>> res;
	void findPalindrome(string rest,vector<string> prev){
		if(!rest.size()){
			res.push_back(prev);
			return;
		}
		for(int i=1;i<=rest.size();i++){
			vector<string> cur=prev;
			if(isPalindrome(rest.substr(0,i))){
				cur.push_back(rest.substr(0,i));
				findPalindrome(rest.substr(i,-1),cur);
			}
		} 
	}

    vector<vector<string>> partition(string s){
    	vector<string> prev;
    	findPalindrome(s,prev);	
    	for(int i=0;i<res.size();i++){
    		cout<<endl;
    		for(int j=0;j<res[i].size();j++)
    			cout<<res[i][j]<<" ";
    	}
    	return res;
    }

};

int main(){
	Solution s;
	s.partition("aab");
}