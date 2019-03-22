#include <iostream>
#include <vector>
#include <cassert>

using namespace std;
class Solution {
public:
	int d[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
	int m, n;
    vector<vector<bool>> visited;
    vector<pair<int,int>> path;
    bool inArea(int x, int y){
        return x >= 0 && x < m && y >= 0 && y < n;
    }
    bool isEdge(int x,int y){
    	return x+1>=m||x-1<0||y+1>=n||y-1<0;
    }
    bool search(vector<vector<char>>& board,int x,int y){
    	visited[x][y]=true;
    	path.push_back(make_pair(x,y));
    	if(isEdge(x,y)) return true;
    	for(int i=0;i<4;i++){
    		int newx = x + d[i][0];
            int newy = y + d[i][1];
            if(inArea(newx,newy)&&!visited[newx][newy]&&board[newx][newy]=='O') 
            	if(search(board,newx,newy)) return true ;
    	}
    	return false;
    }
    void solve(vector<vector<char>>& board) {
        int flip;
        m=board.size();
        if(m == 0)
            return ;
        n=board[0].size();
        for(int i = 0 ; i < m ; i ++)
            visited.push_back(vector<bool>(n, false));

        for(int i=0;i<board.size();i++)
        	for(int j=0;j<board[i].size();j++)
        		if(board[i][j]=='O'&&!visited[i][j]){      			
        			path.clear();
        			flip=false;
        			if(search(board,i,j)) for(int k=0;k<path.size();k++) board[path[k].first][path[k].second]='X';	
        			cout<<path.size()<<endl;
        		}
    }
};
int main(){
	char b1[4][4]={{'X','X','X','X'},{'X','O','O','X'},{'X','X','O','X'},{'X','O','X','X'}};
	 vector<vector<char>> board;
    for( int i = 0 ; i < 4 ; i ++ )
        board.push_back(vector<char>(b1[i], b1[i] + sizeof(b1[i]) / sizeof(char)));

	Solution s;
	s.solve(board);

}