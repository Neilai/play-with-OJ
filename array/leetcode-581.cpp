#include <cctype>
#include <iostream>
#include <vector>
using namespace std;
class Solution {
   public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        int resL = 0, L = 0, resR = n - 1, R = n - 1;
        while (L + 1 < n && nums[L + 1] >= nums[L]) L++;
        if (L == n - 1) return 0;
        while (R - 1 >= 0 && nums[R - 1] <= nums[R]) R--;
        if (R < L) swap(R, L);
        resL = L, resR = R;
        int minVal = nums[L], maxVal = nums[R];
        while (L <= R) {
            minVal = min(minVal, nums[L]);
            maxVal = max(maxVal, nums[L]);
            L++;
        }
        while (resL >= 0 && minVal < nums[resL]) resL--;
        while (resR < n && maxVal > nums[resR]) resR++;
        return resR - resL - 1;
    }
};