// PAT B1032

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

const int MAXN = 100001;

struct Data {
    long schoolId;
    long sum;
} data[MAXN];

bool cmp(Data a, Data b);

int main() {

    long num;
    long tempSchool, tempGrade;
    // initialize data array
    for(long i = 1; i < MAXN; i++) {
        data[i].schoolId = i;
        data[i].sum = 0;
    }

    scanf("%ld", &num);
    for(long i = 1; i <= num; i++) {
        scanf("%ld %ld", &tempSchool, &tempGrade);
        data[tempSchool].sum += tempGrade;
    }
    sort(data + 1, data + num + 1, cmp);

    printf("%ld %ld", data[1].schoolId, data[1].sum);

    return 0;
}

bool cmp(Data a, Data b) {
    return a.sum > b.sum;
}








