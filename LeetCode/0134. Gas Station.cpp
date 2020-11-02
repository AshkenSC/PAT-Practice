/*
0134. Gas Station

在一条环路上有 N 个加油站，其中第 i 个加油站有汽油 gas[i] 升。
你有一辆油箱容量无限的的汽车，从第 i 个加油站开往第 i+1 个加油站需要消耗汽油 cost[i] 升。你从其中的一个加油站出发，开始时油箱为空。
如果你可以绕环路行驶一周，则返回出发时加油站的编号，否则返回 -1。

思路1：暴力解法。
遍历数组，先检查能否做起点，不能则跳过；
能做起点的就测试能否走一圈，中间走不通则直接跳过，测试下一个。直到遍历完成。

思路2：
官方算法优化了下一次开始的位置，它不从n+1开始尝试，而是从上一次断掉的位置开始下一轮尝试。
官方算法优化的依据是：[A,B,C,D]，如果以A为起点，不能从C到达D，那么以B或C为起点，也一定不能到达D。
（不要看官方解答的分析，直接看代码。不然晕了。）

*/

#include <vector>
using namespace std;

class Solution1 {
public:

    bool isValidStation(vector<int>& gas, vector<int>& cost, int i) {
        int remainGas = 0;
        for (int j = i; j < gas.size(); j++)
        {
            remainGas = remainGas + gas[j] - cost[j];
            if (remainGas < 0)
                return false;
        }
        for (int j = 0; j <= i; j++) {
            remainGas = remainGas + gas[j] - cost[j];
            if (remainGas < 0)
                return false;
        }
        return true;
    }

    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        for (int i = 0; i < gas.size(); i++) {
            if (gas[i] < cost[i])
                continue;
            else {
                if (isValidStation(gas, cost, i))
                    return i;
                else
                    continue;
            }
        }
        return -1;
    }
};

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int len = gas.size();

        int startPos = 0;
        int currentGas = 0, totalGasDiff = 0;
        for (int i = 0; i < len; i++) {
            currentGas += gas[i] - cost[i];
            totalGasDiff += gas[i] - cost[i];
            if (currentGas < 0) {
                startPos = i + 1;   // 直接从当前位下一个位置开始考察
                currentGas = 0;
            }
        }
        if (totalGasDiff < 0)
            return -1;
        else
            return startPos;
    }
};