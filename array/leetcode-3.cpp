#include<vector>
#include<ctime>
#include<cstdlib>
#include<iostream>
// 滑动窗口的经典应用
// 这里用到了一个小技巧 字母和数字等ascci字符都在256以内，所以可以直接用一个长度为256的int数组作为hash
// 什么时候可以用滑动窗口？
// 连续字串相关的最优化问题可以考虑  它和双指针相似 通过一个判定变量可以排除很多数据的时候可以考虑
// 这道题的判定变量是长度
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int map[256]={0};
        int l=0,r=-1;
        int res=0;
        while(r<int(s.size())-1){
            if(!map[int(s[r+1])]){
                r++;
                res=max(res,r-l+1);
                map[int(s[r])]++;    
            }
            else {
                while(map[int(s[r+1])]){
                    map[int(s[l])]--;
                    l++;
                }    
            }
        }
        return res;
    }
};
int main(){
	Solution s;
	cout<<s.lengthOfLongestSubstring("dvdf");		
}