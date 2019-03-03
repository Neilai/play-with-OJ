#include<iostream>
#include<vector>
using namespace std;
//经典
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
    	int r=-1;
    	
    	int minLen=0x3f3f3f3f;
    	int match=0;
    	
        while(!match&&r<int(s.size())){
            r++;
    		map[int(s[r])]++;
    		match=1;
    		for(int i=0;i<t.size();i++){
    			if(map[int(t[i])]<test[int(t[i])]){
                     match=0;break;
                }
    		}
    	};       
    	while(r<int(s.size())){
            while( map[int(s[l])]>test[int(s[l])] || test[int(s[l])]==0){
    			map[int(s[l])]--;
    			l++;
    		}
    		
            minLen=min(minLen,r-l+1);
			if(minLen==r-l+1){
				resultl=l;
				resultr=r;
			}
            r++;
            map[int(s[r])]++;       
    	}
        if(resultl!=-1&&resultr!=-1)
    		return s.substr(resultl,minLen);
    	else
    		return "";
    }
};

int main(){
	Solution s;
	string x="A";
	string y="A";
	cout<<s.minWindow(x,y);
	return 1;
}


// class Solution {
// public:
//     string minWindow(string s, string t) {
//         if (s.size() == 0 || t.size() == 0) return "";
//         vector<int> remaining(128, 0);
//         int required = t.size();
//         for (int i = 0; i < required; i++) remaining[t[i]]++;
//         // left is the start index of the min-length substring ever found
//         int min = INT_MAX, start = 0, left = 0, i = 0;
//         while(i <= s.size() && start < s.size()) {
//             if(required) {
//                 if (i == s.size()) break;
//                 remaining[s[i]]--;
//                 if (remaining[s[i]] >= 0) required--;
//                 i++;
//             } else {
//                 if (i - start < min) {
//                     min = i -start;
//                     left = start;
//                 }
//                 remaining[s[start]]++;
//                 if (remaining[s[start]] > 0) required++;
//                 start++;
//             }
//         }
//         return min == INT_MAX? "" : s.substr(left, min);
//     }
// };