/*
0739. Daily Temperatures

给定一组气温T，返回一个列表。
对于每天的输入，告诉你还要等多少天才会变得更暖和。
如果未来不会变更暖和，返回0。

例如，输入：T = [73, 74, 75, 71, 69, 72, 76, 73]
输出：[1, 1, 4, 2, 1, 1, 0, 0]

注意：temperature数组的长度范围为[1, 3000],每天的温度范围在[30, 100]

思路1：暴力解法（超时）
思路2：改进型暴力解法，有动态规划思想。见注释。
*/

#include <vector>
using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        vector<int> res(T.size(), 0);

        // 从后向前构造结果数组
        for (int i = T.size() - 2; i >= 0; i++) {
            // 但在内层循环，又从当前res[i]位置从前向后遍历
            int j = i + 1;
            while (j < T.size()) {
                // 如果发现i后面有一天j，温度更高，直接赋值天数编号并break
                if (T[j] > T[i]) {
                    res[i] = j;
                    break;
                }
                else {
                    // 如果i后面这一天j，温度更低，并且j天后面也没有温度更高的天了
                    // 那只能说明对i而言，后面更没有温度更高的天了，直接退出循环
                    if (res[j] == 0)
                        break;
                    else 
                    // 如果i后面这一天j，温度更低，且j天后面有温度更高的天
                    // 直接跳转到比j天第一次温度更高的那天，节约时间
                        j += res[j];
                }
            }
        }
    }
};