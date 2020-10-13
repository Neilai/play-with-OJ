#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Solution {
   public:
    void generateParenthesis(int left, int right, string path,
                             vector<string>& res) {
        if (left == 0 && right == 0) {
            res.push_back(path);
            return;
        }
        if (left >= 0) {
            generateParenthesis(left - 1, right, path + '(', res);
        }
        if (right > left) {
            generateParenthesis(left, right - 1, path + ')', res);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        generateParenthesis(n, n, "", res);
        return res;
    }
};

// class Solution {
// public:
//     vector<string> generateParenthesis(int n) {
//         vector<string> ret;
//         helper(ret, "", n, n);
//         return ret;
//     }
//     void helper(vector<string> & res, string str, int left, int right){
//         if(left == 0 && right == 0){
//             res.push_back(str);
//             return;
//         }
//         if(left > 0) helper(res, str + "(", left - 1, right);
//         if(right > left) helper(res, str + ")", left, right - 1);
//     }
// };