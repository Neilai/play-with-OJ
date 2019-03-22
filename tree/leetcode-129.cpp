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
	int sum=0;
	void search(TreeNode* &root,int path){
		path=root->val+path*10;
		if(!root->left&&!root->right) {
			sum+=path;
			return;
		}
		if(root->left)  search(root->left,path);
		if(root->right)  search(root->right,path);
	}
    int sumNumbers(TreeNode* root) {
 		 if(root) search(root,0);      
    	 return sum;
    }
};

// class Solution {
// public:
//     int sumNumbers(TreeNode *root) {
//         if(!root)
//             return 0;
//         sum=0;
//         DFS(root, 0);
//         return sum;
//     }
    
//     void DFS(TreeNode *&node, int currentSum)
//     {
//         currentSum=currentSum*10+node->val;
//         if(!node->left&&!node->right)
//             sum+=currentSum;
//         if(node->left)
//             DFS(node->left, currentSum);
//         if(node->right)
//             DFS(node->right, currentSum);
//     }
// private:
//     int sum;
// };