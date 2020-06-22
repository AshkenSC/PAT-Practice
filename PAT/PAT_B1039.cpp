// PAT B1039

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;

const long MAXN = 1005;

int main() {

    int shopCount[128] = {0};
    int hongCount[128] = {0};
    char shopString[MAXN], hongString[MAXN];
    int insufficient = 0, redundant = 0;
    bool isEnough = true;

    // data input
    fgets(shopString, MAXN, stdin);
    fgets(hongString, MAXN, stdin);

    // calculate
    for(int i = 0; i < strlen(shopString); i++) {
        shopCount[(int)shopString[i]]++;
    }
    for(int i = 0; i < strlen(hongString); i++) {
        hongCount[(int)hongString[i]]++;
    }
    for(int i = 0; i < 128; i++) {
        if(hongCount[i] > shopCount[i]) {
            isEnough = false;
            insufficient += hongCount[i] - shopCount[i];
        }
        else if(hongCount[i] < shopCount[i]) {
            redundant += shopCount[i] - hongCount[i];
        }
    }

    // print result
    if(isEnough == true) {
        printf("Yes %d", redundant);
    }
    else {
        printf("No %d", insufficient);
    }

    return 0;
}



