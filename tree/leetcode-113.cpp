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
    void search(TreeNode* root,vector<int> &path,int current,int sum){
    	path.push_back(root->val);
    	if(current+root->val==sum&&!root->left&&!root->right) result.push_back(path);
    	if(root->left) search(root->left,path,current+root->val,sum);
    	if(root->right) search(root->right,path,current+root->val,sum);
    	path.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
    	vector<int> path;
    	if(root) search(root,path,0,sum);
    	return result;    
    }
};
int main(){

}




// class Solution {
// public:
//     vector<vector<int>> pathSum(TreeNode* root, int sum) {
//         vector<vector<int> > paths;
//         vector<int> path;
//         findPaths(root, sum, path, paths);
//         return paths;  
//     }
// private:
//     void findPaths(TreeNode* node, int sum, vector<int>& path, vector<vector<int> >& paths) {
//         if (!node) return;
//         path.push_back(node -> val);
//         if (!(node -> left) && !(node -> right) && sum == node -> val)
//             paths.push_back(path);
//         findPaths(node -> left, sum - node -> val, path, paths);
//         findPaths(node -> right, sum - node -> val, path, paths);
//         path.pop_back();
//     }
// };