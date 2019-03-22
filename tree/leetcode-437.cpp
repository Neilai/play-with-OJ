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
	int search(TreeNode* root, int pre,int &sum){
		if(!root) return 0;
		return ((pre + root->val)==sum)+search(root->left,pre + root->val,sum)+search(root->right,pre + root->val,sum);
	}
    int pathSum(TreeNode* root, int sum) {
    	if(!root) return 0;    
    	return search(root,0,sum)+pathSum(root->left,sum)+pathSum(root->right,sum);
    }
};



// class Solution {
// public:
//     int pathSum(TreeNode* root, int sum) {
//         if(!root) return 0;
//         return sumUp(root, 0, sum) + pathSum(root->left, sum) + pathSum(root->right, sum);
//     }
// private:
//     int sumUp(TreeNode* root, int pre, int& sum){
//         if(!root) return 0;
//         int current = pre + root->val;
//         return (current == sum) + sumUp(root->left, current, sum) + sumUp(root->right, current, sum);
//     }
// };