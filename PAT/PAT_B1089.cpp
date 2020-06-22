// PAT B1089

/*
使用alibi存储每个人的发言；
使用两层循环遍历玩家，每次选定两人为狼人，检测此假设下各人说谎情况
仅当说谎人数为2，且一人一狼时合法，输出结果并结束
其他状况继续下一轮循环，若循环结束还没找到，则没有解


代码技巧：
如何初始化赋值vector: vector<int> array(length, initValue);
连等赋值：a = b = 1; 合法；
*/

#include <cstdio>
#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int num;
    cin >> num;
    vector<int> alibi(num + 1);

    for(int i = 1; i <= num; i++) {
        cin >> alibi[i];
    }
    for(int i = 1; i <= num; i++) {
        for(int j = i + 1; j <= num; j++) {
            // create two new vectors in every loop
            // kinda waste of memory
            vector<int> liarsId;
            vector<int> role(num + 1, 1);

            role[i] = role[j] = -1;
            for(int k = 1; k <= num; k++) {
                if(alibi[k] * role[abs(alibi[k])] < 0) {
                    liarsId.push_back(k);
                }
            }
            if(liarsId.size() == 2) {
                if(role[liarsId[0]] * role[liarsId[1]] < 0) {
                    cout << i << " " << j;
                    return 0;
                }
                else {
                    continue;
                }
            }
            else {
                continue;
            }
        }
    }

    cout << "No Solution";
    return 0;
}


