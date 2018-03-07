#include<iostream>
using namespace std;
 
struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
 
class Solution {
public:
    int minDepth(TreeNode* root) {
        if(!root)
         	return 0;
        else if(!root->left&&!root->right)
        	return 1;
        else if(root->left&&root->right){
        	int leftDepth  = minDepth(root->left);
	        int rightDepth = minDepth(root->right);
	        return min(leftDepth,rightDepth)+1;
        }
        else if(!root->left&&root->right){
        	return 1+minDepth(root->right);
        } 	        
        else
        	return 1+minDepth(root->left);
    }
};
int main(){
	return 1;
}