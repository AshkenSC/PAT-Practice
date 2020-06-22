// PAT B1028

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;

struct Data {
    char name[10];
    int year;
    int month;
    int day;
} data[100000];

bool cmp(Data a, Data b);

int main() {

    long num;
    long legalNum = 0;   // number of illegal entries
    long long birth;
    Data temp;

    // data input
    scanf("%ld", &num);
    for(long i = 0; i < num; i++) {
        scanf("%s %d/%d/%d",
              temp.name, &temp.year,
              &temp.month, &temp.day);

        // judge if the entry is legal
        birth = temp.year * 10000 + temp.month * 100 + temp.day;

        if(birth > 20140906 || birth < 18140906) {
            continue;
        }
        else {
        // the entry is legal
            data[legalNum++] = temp;
        }
    }

    // sort entries
    sort(data, data + legalNum, cmp);

    // print result
    if(legalNum == 0) {
        printf("0");
    }
    else {
        printf("%ld %s %s", legalNum, data[legalNum-1].name, data[0].name);
    }

    return 0;
}

bool cmp(Data a, Data b) {
    if(a.year != b.year) {
        return a.year > b.year;
    }
    else if(a.month != b.month) {
        return a.month > b.month;
    }
    else if(a.day != b.day) {
        return a.day > b.day;
    }
    else {
        return strcmp(a.name, b.name);
    }
}




