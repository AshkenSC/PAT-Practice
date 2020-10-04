/*
0495. Teemo Attacking

在《英雄联盟》的世界中，有一个叫 “提莫” 的英雄，他的攻击可以让敌方英雄艾希（编者注：寒冰射手）进入中毒状态。现在，给出提莫对艾希的攻击时间序列和提莫攻击的中毒持续时间，你需要输出艾希的中毒状态总时长。

你可以认为提莫在给定的时间点进行攻击，并立即使艾希处于中毒状态。
*/

class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int res = 0;
        if (timeSeries.size() < 1) {
            return 0;
        }
        else {
            for (int i = 1; i < timeSeries.size(); i++) {
                if (timeSeries[i] - timeSeries[i - 1] >= duration)
                    res += duration;
                else
                    res += timeSeries[i] - timeSeries[i - 1];
            }
            res += duration;
        }
        return res;
    }
};