/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
public:
    bool judge(TreeNode *left, TreeNode *right)
    {
        if (!left && !right)
            return true;
        if (!left && right)
            return false;
        if (left && !right)
            return false;
        return left->val == right->val && judge(left->left, right->right) && judge(left->right, right->left);
    }
    bool isSymmetric(TreeNode *root)
    {
        if (!root)
            return true;
        return judge(root->left, root->right);
    }
};