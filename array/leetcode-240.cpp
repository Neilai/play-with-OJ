#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
    bool search(vector<int> &arr, int &target)
    {
        int n = arr.size() - 1;
        int l = 0, r = n;
        int mid;
        while (l <= r)
        {
            if (target > arr[r])
                return false;
            mid = (l + r) / 2;
            if (arr[mid] > target)
                r = mid - 1;
            else if (arr[mid] < target)
                l = mid + 1;
            else
                return true;
        }
        return false;
    }

    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        for (int i = 0; i < matrix.size(); i++)
        {
            if (search(matrix[i], target))
                return true;
        }
        return false;
    }
};