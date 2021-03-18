/*
0042. Trapping Rain Water

思路1：参考解答，方法二，按列求。
对于每一列水：
考察其左边最高墙和右边最高墙，取其中较小值。
然后和当前列比较。如果比当前列高，则可以计算出当前积水。

思路2：用两个数组分别记录：每个位置左边和右边的最高位置。
相比思路1，只需要从左向右，再从右向左遍历两次，再从1到n-2遍历一次，时间复杂度为O(n)。
而思路1对每个位置，都需要从左向右，再从右向左检查，因此时间复杂度是O(n^2)。

思路3：双指针。相比思路2，进一步将空间复杂度降低到O(1)。
参考官方解答下的热门评论。

left_max：左边的最大值，它是从左往右遍历找到的
right_max：右边的最大值，它是从右往左遍历找到的
left：从左往右处理的当前下标
right：从右往左处理的当前下标

定理一：在某个位置i处，它能存的水，取决于它左右两边的最大值中较小的一个。
定理二：当我们从左往右处理到left下标时，左边的最大值left_max对它而言是可信的，但right_max对它而言是不可信的。（见下图，由于中间状况未知，对于left下标而言，right_max未必就是它右边最大的值）
定理三：当我们从右往左处理到right下标时，右边的最大值right_max对它而言是可信的，但left_max对它而言是不可信的。

对于位置left而言，它左边最大值一定是left_max，右边最大值“大于等于”right_max，
这时候，如果left_max<right_max成立，那么它就知道自己能存多少水了。
无论右边将来会不会出现更大的right_max，都不影响这个结果。 
所以当left_max<right_max时，我们就希望去处理left下标，反之，我们希望去处理right下标。

参考：
https://leetcode-cn.com/problems/trapping-rain-water/solution/xiang-xi-tong-su-de-si-lu-fen-xi-duo-jie-fa-by-w-8/
*/

// 思路3，双指针
class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0, right = height.size() - 1;
        int leftMax = 0, rightMax = 0;
        int result = 0;

        while (left <= right) {
            if (leftMax < rightMax) {
                result += max(0, leftMax - height[left]);
                leftMax = max(leftMax, height[left]);
                left++;
            }
            else {
                result += max(0, rightMax - height[right]);
                rightMax = max(rightMax, height[right]);
                right--;
            }
        }

        return result;
    }
};

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
