#include<vector>
#include<iostream>
#include<cctype>
using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> pv(26,0), sv(26,0), res;
        if(s.size() < p.size())
           return res;
        // fill pv, vector of counters for pattern string and sv, vector of counters for the sliding window
        for(int i = 0; i < p.size(); ++i)
        {
            ++pv[p[i]-'a'];
            ++sv[s[i]-'a'];
        }
        if(pv == sv)
           res.push_back(0);

        //here window is moving from left to right across the string. 
        //window size is p.size(), so s.size()-p.size() moves are made 
        for(int i = p.size(); i < s.size(); ++i) 
        {
             // window extends one step to the right. counter for s[i] is incremented 
            ++sv[s[i]-'a'];
            
            // since we added one element to the right, 
            // one element to the left should be forgotten. 
            //counter for s[i-p.size()] is decremented
            --sv[s[i-p.size()]-'a']; 

            // if after move to the right the anagram can be composed, 
            // add new position of window's left point to the result 
            if(pv == sv)  // this comparison takes O(26), i.e O(1), since both vectors are of fixed size 26. Total complexity O(n)*O(1) = O(n)
               res.push_back(i-p.size()+1);
        }
        return res;
    }
};
// 256 character version:

// class Solution {
// public:
//     vector<int> findAnagrams(string s, string p) {
//         vector<int> pv(256,0), sv(256,0), res;
//         if(s.size() < p.size())
//            return res;
//         for(int i = 0; i < p.size(); ++i)
//         {
//             ++pv[p[i]];
//             ++sv[s[i]];
//         }
//         if(pv == sv)
//            res.push_back(0);
//         for(int i = p.size(); i < s.size(); ++i)
//         {
//             ++sv[s[i]];
//             --sv[s[i-p.size()]];
//             if(pv == sv)  // this comparison takes O(256), i.e O(1), since both vectors are of fixed size 256. Total complexity O(n)*O(1) = O(n)
//                res.push_back(i-p.size()+1);
//         }
//         return res;
//     }
// };
int main(){
	string x="11aa";
	// int y=x.substr(1,2).find("b");
	// cout<<x.substr(0,0);
	if(x.find("b")==string::npos){
			cout<<"!";
	};
}