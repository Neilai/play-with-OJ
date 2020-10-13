#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;
class Solution
{
public:
    string decode(string s)
    {
        int begin;
        int num = 0;
        stack<char> xxx;
        string res;
        for (int i = 0; i < s.size(); i++)
        {

            if (s[i] == '[')
            {
                if (xxx.empty())
                {
                    begin = i + 1;
                }
                xxx.push(s[i]);
            }
            else if (s[i] == ']')
            {
                xxx.pop();
                if (xxx.empty())
                {
                    for (int j = 0; j < num; j++)
                    {
                        res += decode(s.substr(begin, i-begin));
                    }
                    num = 0;
                }
            }
            else if (xxx.empty())
            {

                if (isdigit(s[i]))
                {
                    num = num * 10 + s[i] - '0';
                }
                else
                {
                    res += s[i];
                }
            }
            cout<<res<<endl;
        }
        return res;
    }
    string decodeString(string s)
    {
        return decode(s);
    }
};
int main()
{
    Solution s;
    s.decodeString("3[a]2[bc]");
}