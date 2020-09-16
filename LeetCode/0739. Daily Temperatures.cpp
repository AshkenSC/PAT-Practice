/*
0739. Daily Temperatures

给定一组气温T，返回一个列表。
对于每天的输入，告诉你还要等多少天才会变得更暖和。
如果未来不会变更暖和，返回0。

例如，输入：T = [73, 74, 75, 71, 69, 72, 76, 73]
输出：[1, 1, 4, 2, 1, 1, 0, 0]

注意：temperature数组的长度范围为[1, 3000],每天的温度范围在[30, 100]

思路1：暴力解法（超时）

*/

#include <vector>
using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        vector<int> result;
        for (int i = 0; i < T.size(); i++) {
            int waitDay = 0;
            for (int j = i + 1; j < T.size(); j++) {
                // 每往后一天，等待天数就+1
                waitDay++;
                // 一旦遇到温度更高天，就退出循环
                if (T[j] > T[i])
                    break;
                // 如果到最后还没遇到更温暖天，就重置等待天数为0
                if (j == T.size() - 1 && T[j] <= T[i])
                    waitDay = 0;
            }
            result.push_back(waitDay);
        }
        return result;
    }
};