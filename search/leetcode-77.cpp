#include <iostream>
#include <vector>
using namespace std;
class Solution {
   public:
    // vector<bool> used;
    vector<vector<int>> res;
    void findcombine(int n, int index, int k, vector<int> &prev) {
        if (prev.size() == k) {
            res.push_back(prev);
            return;
        }
        if (n - index + 1 < k - prev.size()) return;
        for (int i = index; i <= n; i++) {
            prev.push_back(i);
            findcombine(n, i + 1, k, prev);
            prev.pop_back();
        }
        return;
    }

    vector<vector<int>> combine(int n, int k) {
        res.clear();
        if (n <= 0 || k <= 0 || k > n) return res;
        vector<int> prev;
        // used = vector<bool>(n, false);
        findcombine(n, 1, k, prev);

        for (int i = 0; i < res.size(); i++) {
            for (int j = 0; j < res[i].size(); j++) cout << res[i][j];
            cout << endl;
        }
        return res;
    }
};
int main() {
    Solution s;
    s.combine(4, 2);
}

// class Solution {
//    private:
//     vector<vector<int>> res;

//     void dfs(int n, int k, int start, vector<int> &path) {
//         if (path.size() == k) {
//             res.push_back(path);
//             return;
//         }

//         for (int i = start; i <= n - (k - path.size()) + 1; ++i) {
//             path.push_back(i);
//             dfs(n, k, i + 1, path);
//             path.pop_back();
//         }
//     }

//    public:
//     vector<vector<int>> combine(int n, int k) {
//         if (n <= 0 || k <= 0 || k > n) {
//             return res;
//         }

//         vector<int> path;
//         dfs(n, k, 1, path);
//         return res;
//     }
// };
