// PAT B1090

/*
����Σ��Ʒ��Կ��ܳ���һ�Զ�
��˲�����һά����򵥴洢ĳ��Σ��Ʒ�����
ʹ�ö�άvector����¼ĳ��Σ��Ʒ��Σ�մ���
����ÿ��Σ��Ʒ���ʱ
1���໥���Է�����Σ��Ʒ�б��У�2������Σ��Ʒset��

���������嵥ʱ������set�ų���Σ��Ʒ
��ʣ�µ�Σ��Ʒ�����μ����ǰ��Ԫ���Ƿ�����Σ�մ�����
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

