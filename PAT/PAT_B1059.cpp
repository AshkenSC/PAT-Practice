// PAT B1059

#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
#include <cmath>

using namespace std;

bool isPrime(int a);

int main() {

    // finalRank[i] == 0: not existed
    // finalRank[i] == -1: checked
    int finalRank[10000] = {0};
    int contestantNum, queryNum;

    scanf("%d", &contestantNum);
    for(int i = 1; i <= contestantNum; i++) {
        int tempRank;
        scanf("%04d", &tempRank);
        finalRank[tempRank] = i;
    }
    scanf("%d", &queryNum);
    for(int i = 1; i <= queryNum; i++) {
        int tempQuery;
        scanf("%04d", &tempQuery);
        if(finalRank[tempQuery] == 0) {
            printf("%04d: Are you kidding?\n", tempQuery);
        }
        else if(finalRank[tempQuery] == -1) {
            printf("%04d: Checked\n", tempQuery);
        }
        else if(finalRank[tempQuery] == 1) {
            finalRank[tempQuery] = -1;
            printf("%04d: Mystery Award\n", tempQuery);
        }
        else {
            if(isPrime(finalRank[tempQuery]) == true) {
                finalRank[tempQuery] = -1;
                printf("%04d: Minion\n", tempQuery);
            }
            else {
                finalRank[tempQuery] = -1;
                printf("%04d: Chocolate\n", tempQuery);
            }
        }
    }

    return 0;
}

bool isPrime(int a) {
    bool result = true;
    for(int i = 2; i <= sqrt(a); i++) {
        if(a % i == 0) {
            result = false;
        }
    }
    return result;
}

