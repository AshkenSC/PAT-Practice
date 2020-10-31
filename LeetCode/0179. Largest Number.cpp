/*

0179. Largest Number

给定一组非负整数 nums，重新排列它们每位数字的顺序使之组成一个最大的整数。
注意：输出结果可能非常大，所以你需要返回一个字符串而不是整数。

本题的关键是cmp函数比较规则传递性的证明：
https://leetcode-cn.com/problems/largest-number/solution/zui-da-shu-bi-jiao-gui-ze-chuan-di-xing-yi-ji-suan/

*/


#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {   
public:
    bool cmp(int a, int b) {
        string a_str = to_string(a);
        string b_str = to_string(b);
        return (a_str + b_str) > (b_str + a_str);
    }

    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), cmp);

        if (nums[0] == 0)
            return "0";

        string res;
        for (int i = 0; i < nums.size(); i++) {
            res += to_string(nums[i]);
        }

        return res;
    }
};