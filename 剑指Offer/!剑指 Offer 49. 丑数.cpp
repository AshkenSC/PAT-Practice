/*
剑指 Offer 49. 丑数

我们把只包含质因子 2、3 和 5 的数称作丑数（Ugly Number）。求按从小到大的顺序的第 n 个丑数。

思路：参考264的官方题解。做过了还不会！！
*/

class Solution {
public:
    int nthUglyNumber(int n) {
        int two = 0, three = 0, five = 0;
        vector<int> uglyNumbers;
        uglyNumbers.push_back(1);
        
        for (int i = 1; i < n; ++i) {
            int nextTwo = uglyNumbers[two] * 2;
            int nextThree = uglyNumbers[three] * 3;
            int nextFive = uglyNumbers[five] * 5;

            int current = min(nextTwo, nextThree);
            current = min(current, nextFive);

            if (current == nextTwo) 
                ++two;
            if (current == nextThree) 
                ++three;
            if (current == nextFive) 
                ++five;
            
            uglyNumbers.push_back(current);
        }

        return uglyNumbers[n - 1];
    }
};
