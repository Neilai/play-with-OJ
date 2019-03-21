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
    void search(TreeNode *root,int &sum){
    	if(!root) return;
    	if(root->left&&!root->left->left&&!root->left->right)sum+=root->left->val;
    	else if(root->left) search(root->left,sum);
    	search(root->right,sum);
    }
    int sumOfLeftLeaves(TreeNode* root) {
 		 int sum=0;
 		 search(root,sum);
 		 return sum;
    }
};

int main(){

}



// class Solution {
// public:
//     int sumOfLeftLeaves(TreeNode* root) {
//         if (!root) return 0;
//         if (root->left && !root->left->left && !root->left->right) return root->left->val + sumOfLeftLeaves(root->right);
//         return sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right);
//     }
// };


// int sumOfLeftLeaves(TreeNode* root) {
//         int res = 0;
//         if(!root) return res;
//         stack<TreeNode *> q;
//         q.push(root);
//         while(q.size()){
//             TreeNode *t1 = q.top();
//             q.pop();
//             if (t1->left)
//                 if((!t1->left->right) && (!t1->left->left))
//                     res += t1->left->val;
//                 else
//                     q.push(t1->left);
//             if (t1->right)
//                 q.push(t1->right);
//         }
//         return res;
//     }