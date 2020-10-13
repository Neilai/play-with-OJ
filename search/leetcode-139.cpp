#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution
{
public:
    // vector<pair<int, int>> positions;
    void search(string s, string t, vector<int> &positions)
    {
        int p = 0;
        while ((p = s.find(t, p)) != string::npos)
        {
            positions[p] = t.size();
            p++;
        }
    }
    bool wordBreak(string s, vector<string> &wordDict)
    {
        vector<int> positions(s.size(), -1);
        for (int i = 0; i < wordDict.size(); i++)
            search(s, wordDict[i], positions);
    }
};
int main()
{
    vector<string> word({"a", "abc", "b", "cd"});
    string s = "abcd";
    Solution test;
    cout << test.wordBreak(s, word);
    return 0;
}