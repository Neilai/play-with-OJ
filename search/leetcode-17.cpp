#include <iostream>
#include <vector>
#include <string>
#include <cassert>

using namespace std;

/// 17. Letter Combinations of a Phone Number
/// https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/
/// 时间复杂度: O(2^len(s))
/// 空间复杂度: O(len(s))
class Solution {
private:
    const string letterMap[10] = {
            " ",    //0
            "",     //1
            "abc",  //2
            "def",  //3
            "ghi",  //4
            "jkl",  //5
            "mno",  //6
            "pqrs", //7
            "tuv",  //8
            "wxyz"  //9
    };
    vector<string> res;
    void findCombination(const string &digits, int index, const string &s){
        if(index == digits.size()){
            res.push_back(s);
            return;
        }
        string letters = letterMap[digits[index] - '0'];
        for(int i = 0 ; i < letters.size() ; i ++) findCombination(digits, index+1, s + letters[i]);
        
    }
public:
    vector<string> letterCombinations(string digits) {
        res.clear();
        if(digits == "")
            return res;
        findCombination(digits, 0, "");
        return res;
    }
};

int main() {

    vector<string> res = Solution().letterCombinations("234");
    for(int i = 0 ; i < res.size() ; i ++)
        cout << res[i] << endl;

    return 0;
}