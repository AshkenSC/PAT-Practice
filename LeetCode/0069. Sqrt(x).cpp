/*
0069. Sqrt(x)

实现 int sqrt(int x) 函数。

思路：本来是参考liweiwei的，但是评论指出：
其实不是就是简单的二分吗？跳出来的时候一定是在平方根附近的，
最后判断一下如果平方大于x的话就返回它前面的一个值，否则就正常返回就行了。
（关键是最后一句）

*/

class Solution {
public:
    int mySqrt(int x) {
        long long left = 1, right = x / 2;
        long long mid;
        while (left < right) {
            mid = left + (right - left) / 2;
            if (mid * mid == x)
                right = mid;
            else if (mid * mid > x)
                right = mid;
            else if (mid * mid < x)
                left = mid + 1;
        }
        return left * left < x ? left : left - 1;
    }
};

