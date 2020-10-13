#include <vector>
#include <iostream>
using namespace std;
class Solution
{
public:
    vector<vector<int>> xxx;
    void findTwo(vector<int> &nums, int first, int index, int target)
    {
        int left = index;
        int right = nums.size() - 1;
        // cout << "index" << index << endl;
        while (left < right)
        {
            if (nums[left] + nums[right] == target)
            {
                xxx.push_back(vector<int>({first, nums[left], nums[right]}));
                // cout << "left" << left << " " << nums[left] << " " << nums[left + 1]
                //      << "right" << right << endl;
                left++;
                while (left < nums.size() && nums[left] == nums[left - 1])
                    left++;
            }
            else if (nums[left] + nums[right] > target)
            {
                right--;
                while (right >= 0 && nums[right] == nums[right + 1])
                    right--;
            }
            else
            {
                left++;
                while (left < nums.size() && nums[left] == nums[left - 1])
                    left++;
            }
        }
    }
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        if (nums.size() < 3)
            return xxx;
        sort(nums.begin(), nums.end());
        for (int i = 0; i <= nums.size() - 3;)
        {
            findTwo(nums, nums[i], i + 1, -nums[i]);
            i++;
            while (i < nums.size() && nums[i] == nums[i - 1])
                i++;
        }
        cout << xxx.size() << endl;
        return xxx;
    }
};
int main(int argc, const char **argv)
{
    vector<int> x({-1, 0, 1, 0});
    Solution s;
    s.threeSum(x);
    return 0;
}



vector<vector<int> > threeSum(vector<int> &num) {
    
    vector<vector<int> > res;

    std::sort(num.begin(), num.end());

    for (int i = 0; i < num.size(); i++) {
        
        int target = -num[i];
        int front = i + 1;
        int back = num.size() - 1;

        while (front < back) {

            int sum = num[front] + num[back];
            
            // Finding answer which start from number num[i]
            if (sum < target)
                front++;

            else if (sum > target)
                back--;

            else {
                vector<int> triplet(3, 0);
                triplet[0] = num[i];
                triplet[1] = num[front];
                triplet[2] = num[back];
                res.push_back(triplet);
                
                // Processing duplicates of Number 2
                // Rolling the front pointer to the next different number forwards
                while (front < back && num[front] == triplet[1]) front++;

                // Processing duplicates of Number 3
                // Rolling the back pointer to the next different number backwards
                while (front < back && num[back] == triplet[2]) rear--;
            }
            
        }

        // Processing duplicates of Number 1
        while (i + 1 < num.size() && num[i + 1] == num[i]) 
            i++;

    }
    
    return res;
    
}