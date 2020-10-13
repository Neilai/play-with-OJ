#include <vector>
using namespace std;

class Solution {
   public:
    vector<int> dailyTemperatures(vector<int>& T) {
        int n = T.size();
        vector<int> memo(n, -1);
        vector<int> res(n, 0);
        int prev;
        for (int i = n - 1; i >= 0; i--) {
            prev = i + 1;
            while (prev < n && prev != -1) {
                if (T[i] < T[prev]) {
                    res[i] = prev - i;
                    memo[i] = prev;
                    break;
                } else
                    prev = memo[prev];
            }
        }
        return res;
    }
};


// class Solution {
// public:
//     vector<int> dailyTemperatures(vector<int>& T) {
//         int n = T.size();
//         vector<int> ans(n);
//         stack<int> s;
//         for (int i = 0; i < n; ++i) {
//             while (!s.empty() && T[i] > T[s.top()]) {
//                 int previousIndex = s.top();
//                 ans[previousIndex] = i - previousIndex;
//                 s.pop();
//             }
//             s.push(i);
//         }
//         return ans;
//     }
// };