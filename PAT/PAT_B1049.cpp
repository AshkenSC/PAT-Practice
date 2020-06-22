// PAT B1049

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

int main() {

    double input[100010];
    double sum = 0;
    long num;

    // data input
    scanf("%ld", &num);
    for(int i = 0; i < num; i++) {
        scanf("%lf", &input[i]);
    }

    // calculate
    for(int i = 1, j = num; i <= num; i++) {
        sum += (double)i * (double)(j--) * input[i - 1];
    }

    // print result
    printf("%.2lf", sum);

    return 0;
}

