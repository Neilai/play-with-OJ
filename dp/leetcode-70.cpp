#include<iostream>
using namespace std;

class Solution {
private:
	int mem[1000]={0};
public:
// 超时
//   int climbStairs(int n) {
		// if(n==1)
		// 	return 1;
		// else if(n==2)
		// 	return 2;
		// else
		// 	return climbStairs(n-1)+climbStairs(n-2);        
//   }

	 // int climbStairs(int n){
	 // 	if(n==1){
		// 	return 1;
	 // 	}
		// else if(n==2){
		// 	return 2;
		// }
		// else if(mem[n]!=0)
		// 	 return mem[n];
		// else{
		// 	mem[n]=climbStairs(n-1)+climbStairs(n-2);
		// 	return mem[n];
		// }
	 // }

		int climbStairs(int n){
			if(n==1){
		 		return 1;
	 		}
			else if(n==2){
			 	return 2;
			}
			else {
				int x=1,y=2;
				for(int i=2;i<n;i++){
					int tmp=y;
					y=x+y;
					x=tmp;
				}
				return y;
			}
		}
};

int main(){
	Solution s;
	cout<<s.climbStairs(3);

}