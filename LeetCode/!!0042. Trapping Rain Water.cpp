/*
0042. Trapping Rain Water

思路1：参考解答，方法二，按列求。
对于每一列水：
考察其左边最高墙和右边最高墙，取其中较小值。
然后和当前列比较。如果比当前列高，则可以计算出当前积水。

思路2：用两个数组分别记录：每个位置左边和右边的最高位置。
相比思路1，只需要从左向右，再从右向左遍历两次，再从1到n-2遍历一次，时间复杂度为O(n)。
而思路1对每个位置，都需要从左向右，再从右向左检查，因此时间复杂度是O(n^2)。

参考：
https://leetcode-cn.com/problems/trapping-rain-water/solution/xiang-xi-tong-su-de-si-lu-fen-xi-duo-jie-fa-by-w-8/
*/

// 思路2，用两个数组记录每个位置左边和右边的最高位置
class Solution {
public:
    int trap(vector<int>& height) {
        // 考虑空列表情况
        if (height.empty()) {
            return 0;
        }

        int result = 0;
        // 用两个数组记录当前位置左边和右边最高值
        int n = height.size();
        vector<int> leftMax(n);
        vector<int> rightMax(n);
        // 求leftMax数组（第0个位置左边最高值为0）
        int tempMax = height[0];
        for (int i = 1; i < n; ++i) {
            leftMax[i] = tempMax;
            tempMax = max(tempMax, height[i]);
        }
        // 求rightMax（最后一个位置右边最高值为0）
        tempMax = height[n - 1];
        for (int i = n - 2; i >= 0; --i) {
            rightMax[i] = tempMax;
            tempMax = max(tempMax, height[i]);
        }

        // 遍历求结果
        // 注意当前位置必须比左右两侧最高位的较小者还要矮才有积水
        for (int i = 1; i < n - 1; ++i) {
            result += max(min(leftMax[i], rightMax[i]) - height[i], 0);
        }

        return result;
    }
};


// 思路1
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
