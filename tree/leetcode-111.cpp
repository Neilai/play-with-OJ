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
        if(!root) return 0;
        if(!root->left&&!root->right) return 1;
        if(root->left&&root->right) return min(minDepth(root->right),minDepth(root->left))+1;
        if(!root->left&&root->right) return 1+minDepth(root->right); 
        return 1+minDepth(root->left);
    }
};
int main(){
	return 1;
}




// int minDepth(TreeNode* root) {
//     if (root == NULL) return 0;
//     queue<TreeNode*> Q;
//     Q.push(root);
//     int i = 0;
//     while (!Q.empty()) {
//         i++;
//         int k = Q.size();
//         for (int j=0; j<k; j++) {
//             TreeNode* rt = Q.front();
//             if (rt->left) Q.push(rt->left);
//             if (rt->right) Q.push(rt->right);
//             Q.pop();
//             if (rt->left==NULL && rt->right==NULL) return i;
//         }
//     }
//     return -1; //For the compiler thing. The code never runs here.
// }