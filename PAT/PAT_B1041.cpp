// PAT B1041

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;

const int MAXN = 1000;

struct Info {
    char id[20];
    int seatId;
} info[MAXN];

int main() {

    int testeeNum, queryNum;
    int queryMachineId[MAXN];
    Info tempInfo;  int tempMachineId;

    // data input
    scanf("%d", &testeeNum);
    for(int i = 0; i < testeeNum; i++) {
        scanf("%s %d %d", &tempInfo.id, &tempMachineId, &tempInfo.seatId);
        info[tempMachineId] = tempInfo;
    }
    scanf("%d", &queryNum);
    for(int i = 0; i < queryNum; i++) {
        scanf("%d", &queryMachineId[i]);
    }

    // search and print result
    for(int i = 0; i < queryNum; i++) {
        printf("%s %d\n", info[queryMachineId[i]].id, info[queryMachineId[i]].seatId);
    }

    return 0;
}



