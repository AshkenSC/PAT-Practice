/*
0338. Counting Bits

给定一个非负整数，对每个在 0 ≤ i ≤ num范围内的整数i，计算它们二进制形式下含有1的个数，以数组形式返回。

思路1：用STL的bitset，其中的count函数进行1个数的计数。

思路2：动态规划。
初始状态：f(0) = 0, f(1) = 1
除了初始状态的两个数0和1以外，其他数都可以视作，由之前的某个数，在最高位加一个1得到。
例如2，就是00在最高位加一个1得到；5，就是001在最高位加一个1得到。

那么如何找到当前数的前一个数呢？也就是说，对于2，如何定位到0；对于5，如何定位到1？
设当前数为n，那么可以计算log(n)/log(2)（根据换底公式，实际上就是log以2为底，n的对数），然后对其取整。
再由n - 2 ^ int(log(n)/log(2))，即可得到前一个数。

比如对5，int(log(5)/log(2)) = 2，那么前一个数是5 - 2 ^ 2 = 1
这样，我们就找到了状态转移方程。
*/

// 思路1
class Solution {
public:
    vector<int> countBits(int num)
    {
        vector<int> result;
        for (int i = 0; i <= num; i++)
        {
            std::bitset<32> bits(i);
            result.push_back(bits.count());
        }
        return result;
    }
};

// 思路2
class Solution {
public:
    vector<int> countBits(int num)
    {
        vector<int> result;
        result.push_back(0);
        if (num < 1)
            return result;
        result.push_back(1);
        for (int i = 2; i <= num; i++)
        {
            int highest_pos = int(log(i) / log(2));
            int current = result[i - pow(2, highest_pos)] + 1;
            result.push_back(current);
        }
        return result;
    }
};

