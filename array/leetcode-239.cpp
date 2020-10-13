#include <vector>
#include <queue>
using namespace std;
class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        int left = 0, right = 2;
        vector<int> res;
        priority_queue<int, vector<int>, greater<int>> q;
        q.push(nums[0]);
        q.push(nums[1]);
        q.push(nums[2]);
        while(right<nums.size()){
            res.push_back(q.top());
            q.pop();
            q.
        }
    }
};