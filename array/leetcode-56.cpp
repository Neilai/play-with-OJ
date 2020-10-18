#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
class Solution {
   public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(
            intervals.begin(), intervals.end(),
            [](vector<int>& a, vector<int>& b) -> bool { return a[0] < b[0]; });
        vector<vector<int>> res;
        int cur = 0, next = 1, l, r;
        while (cur < intervals.size()) {
            l = intervals[cur][0];
            r = intervals[cur][1];
            while (next < intervals.size() && r >= intervals[next][0]) {
                cur++;
                next++;
                r = max(r, intervals[cur][1]);
            }
            res.push_back(vector<int>{l, r});
            cur++;
            next++;
        }
        return res;
    }
};

//    vector<vector<int>> merge(vector<vector<int>>& intervals) {
//         sort(intervals.begin(), intervals.end());
//         vector<vector<int>> ans;
//         for (int i = 0; i < intervals.size();) {
//             int t = intervals[i][1];
//             int j = i + 1;
//             while (j < intervals.size() && intervals[j][0] <= t) {
//                 t = max(t, intervals[j][1]);
//                 j++;
//             }
//             ans.push_back({ intervals[i][0], t });
//             i = j;
//         }
//         return ans;
//     }
