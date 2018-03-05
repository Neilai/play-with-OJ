#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    string minWindow(string s, string t) {
    	int map[256]={0};
    	int test[256]={0};
    	for(int i=0;i<t.size();i++)
    		test[int(t[i])]++;
    	int resultl=-1;
    	int resultr=-1;
    	int l=0;
    	int r=0;
    	
    	int minLen=0x3f3f3f3f;
    	int match=0;
    	
        while(!match&&r<=int(s.size())){
    		map[int(s[r])]++;
    		r++;
    		match=1;
    		for(int i=0;i<t.size();i++){
    			if(map[int(t[i])]<test[int(t[i])]){
                     match=0;break;
                }
    		}
    	};
       

    	while(r<=int(s.size())){
    		while( map[int(s[l])]>test[int(s[l])] || test[int(s[l])]==0){
    			map[int(s[l])]--;
    			l++;
    		}
    		minLen=min(minLen,r-l+1);
			if(minLen==r-l+1){
				resultl=l;
				resultr=r;
			}

			map[int(s[r])]++;   	
    		r++;
    	}
    	// cout<<resultl<<endl;
    	// cout<<resultr<<endl;
    	if(resultl!=-1&&resultr!=-1)
    		return s.substr(resultl,resultr-resultl);
    	else
    		return "";
    }
};

int main(){
	Solution s;
	string x="A";
	string y="B";
	cout<<s.minWindow(x,y);
	return 1;
}