/*
0399. Evaluate Division

给出方程式A / B = k, 其中A 和B 均为用字符串表示的变量，k 是一个浮点型数字。
根据已知方程式求解问题，并返回计算结果。如果结果不存在，则返回-1.0。

示例 :
给定a / b = 2.0, b / c = 3.0
问题: a / c = ?, b / a = ?, a / e = ?, a / a = ?, x / x = ?
返回[6.0, 0.5, -1.0, 1.0, -1.0 ]
*/

class Solution {
public:

    unordered_map<string, string> parents;  // 存当前节点的父母
    unordered_map<string, double> weights;  // 存 当前节点值/父母值 的结果

    // 返回root以及a/root的值
    pair <string, double> MyFind(string a) {
        if (parents.find(a) == parents.end())
            return {"", -1.0};
        double result = 1.0;
    }

    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
    }
};