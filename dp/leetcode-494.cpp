#include <iostream>
#include <vector>
#include <cmath>
#include <unordered_map>
using namespace std;
// class Solution
// {
// public:
//     int findTargetSumWays(vector<int> &nums, int S)
//     {
//         unordered_map<int, int> ans;
//         ans[0] = 1;
//         for (int n : nums)
//         {
//             unordered_map<int, int> newAns;
//             for (auto p : ans)
//             {
//                 int sum = p.first, cnt = p.second;
//                 newAns[sum + n] += cnt;
//                 newAns[sum - n] += cnt;
//             }
//             ans = newAns;
//         }
//         return ans[S];
//     }
// };

// class Solution {
// private:
//   int cnt = 0;
//   void dfs(vector<int>& nums, long long  S, int start) {
//     if (start == nums.size()) {
//       cnt += !S;
//       return;
//     }
//     dfs(nums, S + nums[start], start + 1);
//     dfs(nums, S - nums[start], start + 1);
//   }
// public:
//   int findTargetSumWays(vector<int>& nums, int S) {
//     dfs(nums, S, 0);
//     return cnt;
//   }
// };


// class Solution {
// public:
//     int findTargetSumWays(vector<int>& nums, int s) {
//         int sum = accumulate(nums.begin(), nums.end(), 0);
//         return sum < s || (s + sum) & 1 ? 0 : subsetSum(nums, (s + sum) >> 1); 
//     }   

//     int subsetSum(vector<int>& nums, int s) {
//         int dp[s + 1] = { 0 };
//         dp[0] = 1;
//         for (int n : nums)
//             for (int i = s; i >= n; i--)
//                 dp[i] += dp[i - n];
//         return dp[s];
//     }
// };
