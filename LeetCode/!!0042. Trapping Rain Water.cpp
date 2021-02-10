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
        // 测试样例中有空列表情况
        if (height.empty()) {
            return 0;
        }

        int sum = 0;

        // 考察范围排除左右两端，必不可能积水
        for (int i = 1; i < height.size() - 1; ++i) {
            // 找到左边最高点
            int leftMax = 0;
            for (int j = i - 1; j >= 0; --j) {
                if (height[j] > leftMax) {
                    leftMax = height[j];
                }
            }

            // 找到右边最高点
            int rightMax = 0;
            for (int j = i + 1; j < height.size(); ++j) {
                if (height[j] > rightMax) {
                    rightMax = height[j];
                }
            }

            // 计算当前位置会有多少积水
            int minLR = min(leftMax, rightMax);
            // 如果当前位置的高度大于两边最高点的较小者，则不会积水
            if (minLR > height[i]) {
                sum += minLR - height[i];
            }
        }

        return sum;
    }
};