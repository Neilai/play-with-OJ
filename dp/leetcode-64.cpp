#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
    	for(int i=1;i<grid[0].size();i++)
    		grid[0][i]=grid[0][i]+grid[0][i-1];
    	for(int i=1;i<grid.size();i++)
    		grid[i][0]=grid[i][0]+grid[i-1][0];
  
    	for (int i = 0; i < grid.size(); ++i){
    		for(int j=0;j<grid[i].size();++j)
    			cout<<grid[i][j]<<" ";
    		cout<<endl;
    	}
    	for(int i=1;i<grid.size();i++)
    		for(int j=1;j<grid[i].size();j++)
    			grid[i][j]=grid[i][j]+min(grid[i][j-1],grid[i-1][j]);
    	return grid[grid.size()-1][grid[grid.size()-1].size()-1];
        
    }
};
int main(){
	Solution a;
	vector<vector<int>> s;
	vector<int> x;
	vector<int> y;
	vector<int> z;
	x.push_back(1);x.push_back(3);x.push_back(1);
	y.push_back(1);y.push_back(5);y.push_back(1);
	z.push_back(4);z.push_back(2);z.push_back(1);
	s.push_back(x);s.push_back(y);s.push_back(z);
	cout<<a.minPathSum(s);
}