#include <vector>
using namespace std;
class Solution
{
public:
    int BitCount(unsigned int n)
    {
        unsigned int c = 0;     // 计数器
        for (c = 0; n; n >>= 1) // 循环移位
            c += n & 1;         // 如果当前位是1，则计数器加1
        return c;
    }

    vector<int> countBits(int num)
    {
        vector<int> res(num + 1);
        for (int i = 0; i <= num; i++)
            res[i] = (BitCount(i));
        return res;
    }
};

// class Solution {
// public:
//     vector<int> countBits(int num) {
//         vector<int> res(num + 1, 0);
//         for (int i = 1; i <= num; ++i) {
//             res[i] = res[i >> 1] + (i & 1);
//         }
//         return res;
//     }
// };