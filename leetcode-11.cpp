#include<vector>
using namespace std;
// 双指针法 优化暴力解法 关键是要找出舍弃条件 
// 也就是说找到一个判定变量  可以排除  固定一个点 另外一个点一条线的情况
// 排除后，就可以进行指针移动
// 这一题的判定变量是 短板效应的最短长度
class Solution {
public:
    int maxArea(vector<int>& height) {
        int res=0;
        int l=0,r=height.size()-1;
        while(l<r){
        	res=max(res,(r-l)*min(height[l], height[r]));
        	if(height[l] < height[r])
                 ++ l;
            else
                 -- r;
        }
        return res;
    }
};