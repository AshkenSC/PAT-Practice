/*
0207. Course Schedule

你这个学期必须选修 numCourse 门课程，记为 0 到 numCourse-1 。
在选修某些课程之前需要一些先修课程。 例如，想要学习课程 0 ，你需要先完成课程 1 ，我们用一个匹配来表示他们：[0,1]
给定课程总量以及它们的先决条件，请你判断是否可能完成所有课程的学习？

思路：参考官方解答
*/

#include <vector>
using namespace std;

class Solution {
private:
    vector<vector<int>> edges;
    vector<int> visited;
    bool isValid = true;

public:
    // visted数组元素有三个可能取值，代表结点的三种状态：
    // 0：结点未被访问
    // 1：结点正在被访问，但其相邻结点还没有全部访问完毕
    // 2：结点已经访问完毕
    void dfs(int u) {
        visited[u] = 1;
        for (int v : edges[u]) {
            if (visited[v] == 0) {
                dfs(v);
                if (isValid == false)
                    return;
            }
            else if (visited[v] == 1) {
                isValid = false;
                return;
            }
        }
        visited[u] = 2;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        edges.resize(numCourses);
        visited.resize(numCourses);
        for (const auto& entry : prerequisites) {
            edges[entry[1]].push_back(entry[0]);
        }
        for (int i = 0; i < numCourses && isValid; i++) {
            if (!visited[i]) {
                dfs(i);
            }
        }
        return isValid;
    }
};