// PAT B1026

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {

    long long time1, time2;
    int hour, minute, second;
    double total;

    scanf("%lld %lld", &time1, &time2);

    // total currently stores total hours
    total = (time2 - time1) / 100.0 / 3600.0;
    hour = (int)total;

    // total currently stores total minutes left
    total = (total - (int)total) * 60.0;
    minute = (int)total;

    // total currently stores total seconds left
    total = (total - (int)total) * 60.0;
    if(total - (int)total >= 0.4449) {
    // x.5 = x + 1
        second = (int)total + 1;
    }
    else {
    // x.4 = x
        second = (int)total;
    }

    // print result
    printf("%02d:%02d:%02d", hour, minute, second);

    return 0;
}





