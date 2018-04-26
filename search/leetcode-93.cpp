#include <iostream>
#include <vector>
#include <string>
#include <cassert>
#include <cstdlib>
using namespace std;
// 搜索  注意搜索状态需要相互隔离
class Solution {
public:
	vector<string> res;
	bool isValid(string s){
		if(!s.size())
			return 0;
		else if(s.size()==1&&s[0]=='0')
			return 1;
		else if(s[0]=='0')
			return 0;
		else
			return atoi(s.c_str())>=1&&atoi(s.c_str())<=255;
	}
	void addRes(vector<string> s){
		string ip;
		ip=s[0]+"."+s[1]+"."+s[2]+"."+s[3];
		res.push_back(ip);
	}
	void findIp(string rest,vector<string> prev){
		if(prev.size()==3){
			if(isValid(rest)){
				prev.push_back(rest);
				addRes(prev);
			}
		}
		else{
			int pos=min(int(rest.size()),3);
			for(int i=0;i<pos;i++){
				if(isValid(rest.substr(0,i+1))){
					vector<string> cur=prev;
					cur.push_back(rest.substr(0,i+1));
					findIp(rest.substr(i+1),cur);
				}
			}
		}
	}
    vector<string> restoreIpAddresses(string s) {
    	vector<string> prev;
    	findIp(s,prev);
    	for(int i=0;i<res.size();i++)
    		cout<<res[i]<<endl;
    	return res;
    }
};
int main(){
	// string s="123";
 	// char* x[3];
	// s.copy(x[0],3,1);
	// cout<<x[0];
	// cout<<stoi(s.substr(1));
	Solution s;
	string x="010010";
	s.restoreIpAddresses(x);
}