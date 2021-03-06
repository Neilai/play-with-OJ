#include <iostream>
#include <vector>
using namespace std;
class Solution {
   public:
    void combine(vector<int>& nums, int k, int index, vector<vector<int>>& res,
                 vector<int>& path) {
        if (k == path.size()) {
            res.push_back(path);
            return;
        }
        if (k - path.size() >nums.size() - index) return;
        // k-path.size()   path.size()-index-1
        for (int i = index; i < nums.size(); i++) {
            path.push_back(nums[i]);
            combine(nums, k, i + 1, res, path);
            path.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> path;
        res.push_back(vector<int>());
        for (int i = 1; i <= nums.size(); i++) {
            combine(nums, i, 0, res, path);
        }
        return res;
    }
};