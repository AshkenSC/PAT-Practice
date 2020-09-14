/*
0287. Find the Duplicate Number

给定一个包含 n + 1 个整数的数组 nums，其数字都在 1 到 n 之间（包括 1 和 n），可知至少存在一个重复的整数。
假设只有一个重复的整数，找出这个重复的数。

思路：二分法，抽屉原理
找到1到n的中间数n/2。
然后遍历整个数组，判断小于等于n/2的数有多少个。
如果超过n/2个，则说明重复的整数一定在1到n/2范围内。

假设超过n/2个：再次遍历整个数组，这次设中间数为n/4。
再次遍历整个数组，判断小于等于n/4的数有多少个……

*/

#include <vector>
using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int len = nums.size();
        int left = 0;
        int right = len - 1;

        while (left < right) {
            int mid = left + (right - left) / 2;
            int cnt =  0;

            // 遍历整个数组，判断小于等于当前mid的数有多少个
            for(int num : nums) {
                if (num <= mid)
                    cnt++;
            }

            // 如果小于等于mid的数超过mid个，则说明重复的整数一定在[left, mid]范围内
            if (cnt > mid) {
                right = mid;
            }
            // 反之，则在[mid + 1, right]范围内
            else {
                left = mid + 1;
            }
        }

        return left;
    }
};
