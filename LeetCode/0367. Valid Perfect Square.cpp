/*
0367. Valid Perfect Square

给定一个正整数 num，编写一个函数，如果 num 是一个完全平方数，则返回 True，否则返回 False。
说明：不要使用任何内置的库函数，如  sqrt。

思路：二分法，在2到num/2内找该数的平方根。
*/


class Solution {
public:
    bool isPerfectSquare(int num) {
        if (num < 2)
            return true;

        long long left = 2, right = num / 2;
        long long mid;
        while (left <= right) {
            mid = left + (right - left) / 2;
            if (mid * mid == num)
                return true;
            else if (mid * mid > num)
                right = mid - 1;
            else if (mid * mid < num)
                left = mid + 1;
        }
        return false;
    }
};
