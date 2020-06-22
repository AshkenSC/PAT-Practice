// PAT B1082

#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int num;
    long long minDist = 20001, maxDist = -1;
    int bestId, worstId;

    cin >> num;
    int x, y, dist, tempId;
    for(int i = 0; i < num; i++) {
        dist = 0;
        cin >> tempId >> x >> y;
        dist = x * x + y * y;
        if(dist < minDist) {
            minDist = dist;
            bestId = tempId;
        }
        if(dist > maxDist) {
            maxDist = dist;
            worstId = tempId;
        }
    }
    printf("%04d %04d", bestId, worstId);

    return 0;
}


