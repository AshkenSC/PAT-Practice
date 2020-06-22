// PAT B1038

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;

const long MAXN = 100000;

int main() {

    long num, queryNum;
    int grades[MAXN];
    int queryGrades[MAXN];
    long queryResults[101] = {0};

    // data input
    scanf("%ld", &num);
    for(long i = 0; i < num; i++) {
        scanf("%d", &grades[i]);
    }
    scanf("%ld", &queryNum);
    for(long i = 0; i < queryNum; i++) {
        scanf("%d", &queryGrades[i]);
    }

    // search
    for(long i = 0; i < num; i++) {
        for(long j = 0; j < queryNum; j++) {
            if(queryGrades[j] == grades[i]) {
                queryResults[grades[i]]++;
                break;
            }
        }
    }

    // print results
    for(long i = 0; i < queryNum; i++) {
        printf("%ld", queryResults[queryGrades[i]]);
        if(i < queryNum - 1) {
            printf(" ");
        }
    }

    return 0;
}



