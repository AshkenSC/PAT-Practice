/*
0621. Task Scheduler

给定一个用字符数组表示的 CPU 需要执行的任务列表。其中包含使用大写的 A - Z 字母表示的26 种不同种类的任务。任务可以以任意顺序执行，并且每个任务都可以在 1 个单位时间内执行完。CPU 在任何一个单位时间内都可以执行一个任务，或者在待命状态。
然而，两个相同种类的任务之间必须有长度为 n 的冷却时间，因此至少有连续 n 个单位时间内 CPU 在执行不同的任务，或者在待命状态。
你需要计算完成所有任务所需要的最短时间。

思路：
1.将任务按照数量从多到少排序。
2.先安排数量最多的那个任务，然后再从剩下的里面依次选择任务安排，填满冷却时间n。
3.如果发现剩下的任务不够n了，只能等待了。
4.等待满n，然后继续选择剩下最多的那个任务。

*/

#include <vector>
#include <map>
#include <algorithm>
using namespace std;

class Solution {

public:
    int leastInterval(vector<char>& tasks, int n) {
        // 将任务统计数量，并按照个数排序
        // 其实这里并不需要使用map，用数组即可。因为我们只是要算最后总共最少需要多少时间，不在乎每个具体的任务。
        // 因此如果直接用数组排序，那么A排序后换到了C位置，D排序后换到了A位置，但是这样并不影响总时间的计算，只是每个人代号变了罢了。
        
        // 统计任务数量，并排序
        vector<int> taskCount(26);
        for (int i = 0; i < tasks.size(); i++) {
            taskCount[tasks[i] - 'A']++;
        }
        // 将任务从少到多排序
        sort(taskCount.begin(), taskCount.end());

        // 安排任务
        int totalTime = 0;
        while (taskCount[25] > 0) {
            int i = 0;
            while (i <= n) {
                // 如果最多的任务数也为0，循环结束
                if (taskCount[25] == 0)
                    break;
                // 尽量安排n个不同的任务，根据任务数从多到少依次安排。
                // 如果任务数量不足n个，只能不安排而空等待了
                if (i < 26 && taskCount[25 - i] > 0)
                    taskCount[25 - i]--;
                totalTime++;
                i++;
            }
            sort(taskCount.begin(), taskCount.end());
        }

        return totalTime;
    }
};