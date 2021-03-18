/*
0042. Trapping Rain Water

思路：参考解答，方法二，按列求。
对于每一列水：
考察其左边最高墙和右边最高墙，取其中较小值。
然后和当前列比较。如果比当前列高，则可以计算出当前积水。

参考：
https://leetcode-cn.com/problems/trapping-rain-water/solution/xiang-xi-tong-su-de-si-lu-fen-xi-duo-jie-fa-by-w-8/
*/

class Solution {
public:
    int trap(vector<int>& height) {
        // 考虑空列表情况
        if (height.empty()) {
            return 0;
        }

        int result = 0;
        // 遍历数组（排除第一个和最后一个）
        for (int i = 1; i < height.size() - 1; ++i) {
            // 找左边最大值
            int leftMax = 0;
            for (int j = 0; j < i; ++j) {
                if (height[j] > leftMax) {
                    leftMax = height[j];
                }
            }

            // 找右边最大值
            int rightMax = 0;
            for (int j = height.size() - 1; j > i; --j) {
                if (height[j] > rightMax) {
                    rightMax = height[j];
                }
            }

            // 计算当前位置积水
            // 注意当前位置必须比左右两侧最高位的较小者还要矮才有积水
            result += max(min(leftMax, rightMax) - height[i], 0);
        }

        return result;
    }
};
