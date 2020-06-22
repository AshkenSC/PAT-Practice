// PAT B1015

#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

const int MAXN = 100050;

struct Data {
    char id[10];
    int de;
    int cai;
    int sum;
    int level;
} data[MAXN];

bool cmp(Data a, Data b);

int main() {
    long num;
    long qualifiedNum = 0;
    int low, high;

    scanf("%d %d %d", &num, &low, &high);
    for(long i = 0; i < num; i++) {
        scanf("%s %d %d", data[i].id, &data[i].de, &data[i].cai);
        data[i].sum = data[i].de + data[i].cai;
        if(data[i].de >= high && data[i].cai >= high) {
            data[i].level = 1;
            qualifiedNum++;
        }
        else if(data[i].de >= high &&
                data[i].cai >= low && data[i].cai < high) {
            data[i].level = 2;
            qualifiedNum++;
        }
        else if(data[i].de < high &&
                data[i].cai >= low && data[i].cai < high &&
                data[i].de >= data[i].cai) {
            data[i].level = 3;
            qualifiedNum++;
        }
        else if(data[i].de >= low && data[i].cai >= low) {
            data[i].level = 4;
            qualifiedNum++;
        }
        else {
            data[i].level = 5;
        }
    }

    sort(data, data + num, cmp);

    printf("%ld\n", qualifiedNum);
    for(long i = 0; i < qualifiedNum; i++) {
        printf("%s %d %d", data[i].id, data[i].de, data[i].cai);
        if(i != qualifiedNum - 1) {
        // format control
            printf("\n");
        }
    }

    return 0;
}

bool cmp(Data a, Data b) {
    if(a.level != b.level) {
        return a.level < b.level;
    }
    else if(a.sum != b.sum){
        return a.sum > b.sum;
    }
    else if(a.de != b.de) {
        return a.de > b.de;
    }
    else {
        return strcmp(a.id, b.id) < 0;
    }
}





