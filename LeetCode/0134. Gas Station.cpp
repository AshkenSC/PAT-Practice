/*
0134. Gas Station

在一条环路上有 N 个加油站，其中第 i 个加油站有汽油 gas[i] 升。
你有一辆油箱容量无限的的汽车，从第 i 个加油站开往第 i+1 个加油站需要消耗汽油 cost[i] 升。你从其中的一个加油站出发，开始时油箱为空。
如果你可以绕环路行驶一周，则返回出发时加油站的编号，否则返回 -1。

思路1：暴力解法。
遍历数组，先检查能否做起点，不能则跳过；
能做起点的就测试能否走一圈，中间走不通则直接跳过，测试下一个。直到遍历完成。

*/

#include <vector>
using namespace std;

class Solution {
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