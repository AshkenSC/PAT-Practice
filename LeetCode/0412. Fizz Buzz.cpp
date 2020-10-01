/*
0412. Fizz Buzz

写一个程序，输出从 1 到 n 数字的字符串表示。
1. 如果 n 是3的倍数，输出“Fizz”；
2. 如果 n 是5的倍数，输出“Buzz”；
3.如果 n 同时是3和5的倍数，输出 “FizzBuzz”。

*/

#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> res;
        for (int i = 1; i <= n; i++) {
            string currentStr;
            if (i % 3 == 0)
                currentStr += "Fizz";
            if (i % 5 == 0)
                currentStr += "Buzz";
            if (currentStr.size() == 0)
                currentStr += to_string(i);
            res.push_back(currentStr);
        }
        return res;
    }
};