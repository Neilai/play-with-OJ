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
	vector<string> result;
	void search(TreeNode *root,string path){
		if(!root->left&&!root->right) {
			result.push_back(path);
			return;
		}
		if(root->left) search(root->left,path+"->"+to_string(root->left->val));
		if(root->right) search(root->right,path+"->"+to_string(root->right->val));
	}
    vector<string> binaryTreePaths(TreeNode* root) {
    	if(root){
			string path=to_string(root->val);
    		search(root,path);
    	}
    	return result;  
    }
};
int main(){

}