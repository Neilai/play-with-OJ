#include<iostream>
#include<vector>
using namespace std;  
struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
	vector<vector<int>> result;
    void search(TreeNode* root,vector<int> path,int current,int sum){
    	path.push_back(root->val);
    	if(current+root->val>sum) return;
    	if(current+root->val==sum){
    		result.push_back(path);
    		return;
    	}
    	if(root->left) search(root->left,path,current+root->val,sum);
    	if(root->right) search(root->right,path,current+root->val,sum);
    }
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
    	vector<int> path;
    	path.push_back(root->val);
    	search(root,path,root->val,sum);
    	return result;    
    }
};
int main(){

}