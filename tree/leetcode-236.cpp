#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
   public:
    unordered_map<TreeNode*, pair<int, int>> mp;
    bool findElement(TreeNode* root, TreeNode* p, int len) {
        if (!root) return false;
        if (mp.count(root)) {
            mp[root].first++;
        } else {
            mp[root] = make_pair(1, len);
        }
        if (root->val == p->val) return true;
        if (findElement(root->right, p, len + 1)) return true;
        if (findElement(root->left, p, len + 1)) return true;
        mp[root].first--;
        return false;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        findElement(root, p, 1);
        findElement(root, q, 1);
        TreeNode* parent = root;
        int height = 1;
        for (auto& s : mp) {
            if (s.second.first == 2 && s.second.second > height) {
                height = s.second.second;
                parent = s.first;
            }
        }
        return parent;
    }
};

// class Solution {
// public:
//     TreeNode* ans;
//     bool dfs(TreeNode* root, TreeNode* p, TreeNode* q) {
//         if (root == nullptr) return false;
//         bool lson = dfs(root->left, p, q);
//         bool rson = dfs(root->right, p, q);
//         if ((lson && rson) || ((root->val == p->val || root->val == q->val)
//         && (lson || rson))) {
//             ans = root;
//         }
//         return lson || rson || (root->val == p->val || root->val == q->val);
//     }
//     TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
//     {
//         dfs(root, p, q);
//         return ans;
//     }
// };

// class Solution {
// public:
//     unordered_map<int, TreeNode*> fa;
//     unordered_map<int, bool> vis;
//     void dfs(TreeNode* root){
//         if (root->left != nullptr) {
//             fa[root->left->val] = root;
//             dfs(root->left);
//         }
//         if (root->right != nullptr) {
//             fa[root->right->val] = root;
//             dfs(root->right);
//         }
//     }
//     TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
//     {
//         fa[root->val] = nullptr;
//         dfs(root);
//         while (p != nullptr) {
//             vis[p->val] = true;
//             p = fa[p->val];
//         }
//         while (q != nullptr) {
//             if (vis[q->val]) return q;
//             q = fa[q->val];
//         }
//         return nullptr;
//     }
// };
