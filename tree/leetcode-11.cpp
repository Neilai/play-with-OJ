#include<iostream>
using namespace std;
struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
 //这道题目要非常注意和求最大的区别
 //由于求最小深度一定还是要走到叶结点 如果用之前的方法的话到了空结点也会返回 
 // 所以必须对叶结点单独判断
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