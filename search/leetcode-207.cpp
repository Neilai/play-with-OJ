#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
    bool dfs(vector<vector<int>> &G, vector<int> &visited, vector<int> &path, int cur)
    {
        visited[cur] = true;
        path[cur] = true;
        for (int i = 0; i < G[cur].size(); i++)
        {
            int neighbour = G[cur][i];
            if (path[neighbour])
                return true;
            else if (!visited[neighbour])
            {
                if (dfs(G, visited, path, neighbour))
                    return true;
            }
        }
        path[cur] = false;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        vector<vector<int>> G(numCourses, vector<int>());
        vector<int> visited(numCourses, false);
        vector<int> path(numCourses, false);
        for (int i = 0; i < prerequisites.size(); i++)
        {
            G[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        for (int i = 0; i < visited.size(); i++)
        {
            if (!visited[i])
            {
                if (dfs(G, visited, path, 0))
                    return false;
            }
        }

        return true;
    }
};

// bool canFinish(int n, vector<pair<int, int>>& pre) {
//     vector<vector<int>> adj(n, vector<int>());
//     vector<int> degree(n, 0);
//     for (auto &p: pre) {
//         adj[p.second].push_back(p.first);
//         degree[p.first]++;
//     }
//     queue<int> q;
//     for (int i = 0; i < n; i++)
//         if (degree[i] == 0) q.push(i);
//     while (!q.empty()) {
//         int curr = q.front(); q.pop(); n--;
//         for (auto next: adj[curr])
//             if (--degree[next] == 0) q.push(next);
//     }
//     return n == 0;
// }