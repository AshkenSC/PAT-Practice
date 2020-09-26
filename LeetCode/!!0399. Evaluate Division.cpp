/*
0399. Evaluate Division

给出方程式A / B = k, 其中A 和B 均为用字符串表示的变量，k 是一个浮点型数字。
根据已知方程式求解问题，并返回计算结果。如果结果不存在，则返回-1.0。

示例 :
给定a / b = 2.0, b / c = 3.0
问题: a / c = ?, b / a = ?, a / e = ?, a / a = ?, x / x = ?
返回[6.0, 0.5, -1.0, 1.0, -1.0 ]

思路：带权重的并查集。
参考https://leetcode-cn.com/problems/evaluate-division/solution/c-dai-quan-zhi-de-bing-cha-ji-by-wen-zhong-qiu-she/
*/

#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:

    unordered_map<string, string> parents;  // 存当前节点的父母
    unordered_map<string, double> weights;  // 存 当前节点值/父母值 的结果

    // 返回root以及a/root的值
    pair <string, double> MyFind(string a) {
        if (parents.find(a) == parents.end())
            return {"", -1.0};
        double result = 1.0;
        while (a != parents[a]) {
            // result *= a/parent
            result *= weights[a];   
            a = parents[a];
        }
        // 返回a的根节点，和a/root的结果
        return {a, result};
    }

    // 用a_b表示a除以b的结果
    void MyUnion(string a, string b, double a_b) {
        pair<string, double> p1 = MyFind(a);
        pair<string, double> p2 = MyFind(b);
        if("" == p1.first || "" == p2.first)
            return;
        parents[p1.first] = p2.first;
        weights[p1.first] = 1 / p1.second * a_b * p2.second;    // 更新权重
    }

    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        // 并
        for (int i = 0; i < equations.size(); i++) {
            string a = equations[i][0];
            string b = equations[i][1];
            // 并查集初始化
            if (parents.find(a) == parents.end()) {
                parents[a] = a;
                weights[a] = 1.0;
            }
            if (parents.find(b) == parents.end()) {
                parents[b] = b;
                weights[b] = 1.0;
            }
            // 并
            MyUnion(a, b, values[i]);

            // 查
            vector<double> result;
            for (auto &q : queries) {
                string a = q[0];
                string b = q[1];
                pair<string, double> p1 = MyFind(a);    // p1.second = a/p1
                pair<string, double> p2 = MyFind(b);    // p2.second = b/p2
                if (p1.first != p2.first || "" == p1.first || "" == p2.first) {
                    result.push_back(-1.0);
                }
                else {
                    // a/b = (a/p1) / (b/p2)
                    result.push_back(p1.second / p2.second);
                }
            }
            return result;
        }
    }
};