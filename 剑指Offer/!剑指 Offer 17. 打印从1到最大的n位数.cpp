/*
剑指 Offer 17. 打印从1到最大的n位数

输入数字 n，按顺序打印出从 1 到最大的 n 位十进制数。比如输入 3，则打印出 1、2、3 一直到最大的 3 位数 999。

思路：
回溯法，输出数字全排列。
生疏之处在于如何删除vector指定位置的元素。
*/

class Solution {
private:
    vector<int> res;
    
public:
    void dfs(int n, int curLen, string curStr) {
        if (curLen == n) {
            int num = stoi(curStr);
            res.push_back(num);
            return;
        }

        for (int i = 0; i <= 9; ++i) {
            curStr += '0' + i;
            dfs(n, curLen + 1, curStr);
            // 回溯
            curStr.pop_back();
        }
    }

    vector<int> printNumbers(int n) {
        dfs(n, 0, "");
        // 如何删除vector指定位置元素，生疏了
        res.erase(res.begin());
        return res;
    }
};
