#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>

using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution
{
public:
    int findMax(TreeNode *root)
    {
        if (!root)
            return 0;
        return max(findMax(root->left) + findMax(root->right), root->val + (root->left ? findMax(root->left->left) + findMax(root->left->right) : 0) + (root->right ? findMax(root->right->left) + findMax(root->right->right) : 0));
    }
    int rob(TreeNode *root)
    {
        return findMax(root);
    }
};
int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}

// class Solution {
// public:
//     int tryRob(TreeNode* root, int& l, int& r) {
//         if (!root)
//             return 0;
            
//         int ll = 0, lr = 0, rl = 0, rr = 0;
//         l = tryRob(root->left, ll, lr);
//         r = tryRob(root->right, rl, rr);
        
//         return max(root->val + ll + lr + rl + rr, l + r);
//     }

//     int rob(TreeNode* root) {
//         int l, r;
//         return tryRob(root, l, r);
//     }
// };