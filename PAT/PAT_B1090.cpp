// PAT B1090

/*
由于危险品配对可能出现一对多
因此不能用一维数组简单存储某号危险品的配对
使用二维vector来记录某号危险品的危险搭配
遍历每个危险品配对时
1）相互将对方存入危险品列表中，2）存入危险品set中

遍历货物清单时，利用set排除非危险品
对剩下的危险品，依次检查其前面元素是否在其危险搭配内
*/

#include <cmath>
#include <vector>
#include <set>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int pairNum, listNum;
    int temp1, temp2;
    cin >> pairNum >> listNum;
    // save dangerous items id
    set<int> dangerSet;
    // 2d array saving danger relation
    vector< vector<int> > dangerPairs(100000);

    // danger relation input
    for(int i = 0; i < pairNum; i++) {
        cin >> temp1 >> temp2;
        dangerSet.insert(temp1);
        dangerSet.insert(temp2);
        dangerPairs[temp1].push_back(temp2);
        dangerPairs[temp2].push_back(temp1);
    }

    // cargo list input
    int cargoNum;
    bool isSafe;
    for(int i = 0; i < listNum; i++) {
        isSafe = true;
        cin >> cargoNum;
        set<int> inListDanger;
        for(int j = 0; j < cargoNum; j++) {
            cin >> temp1;
            if(dangerSet.count(temp1) == 0) {
                continue;
            }
            for(int k = 0; k < dangerPairs[temp1].size(); k++) {
                if(inListDanger.count(dangerPairs[temp1][k]) != 0) {
                   isSafe = false;
                   break;
                }
            }
            inListDanger.insert(temp1);
        }
        if(isSafe) {
            cout << "Yes" << endl;
        }
        else {
            cout << "No" << endl;
        }
    }

    return 0;
}

