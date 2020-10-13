#include <string>
#include <unordered_set>
#include <vector>
using namespace std;
class Solution {
   public:
    void combine(vector<int>& nums, int index, int target,
                 vector<vector<int>>& res, vector<int>& path) {
        if (target == 0) {
            res.push_back(path);
            return;
        }
        if (target < 0) return;
        int prev;
        for (int i = index; i < nums.size();) {
            path.push_back(nums[i]);
            combine(nums, i + 1, target - nums[i], res, path);
            path.pop_back();
            prev = i;
            while (i < nums.size() && nums[prev] == nums[i]) {
                i++;
            }
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int> path;
        combine(candidates, 0, target, res, path);
        return res;
    }
};