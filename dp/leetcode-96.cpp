#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
using namespace std;
//根节点 左右子树
class Solution
{
public:
    int numTrees(int n)
    {
        int *G = new int[n + 1];
        memset(G, 0, sizeof(int) * (n + 1));
        G[0] = G[1] = 1;
        for (int i = 2; i <= n; ++i)
        {
            for (int j = 1; j <= i; ++j)
            {
                cout << G[i] << endl;
                G[i] += G[j - 1] * G[i - j];
            }
        }
        return G[n];
    }
};
int main()
{
}
