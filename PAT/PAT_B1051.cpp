// PAT B1051

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

int main() {

    double r1, p1, r2, p2;
    double a1, b1, a2, b2;
    double ans1, ans2;

    scanf("%lf %lf %lf %lf", &r1, &p1, &r2, &p2);
    a1 = r1 * cos(p1);
    b1 = r1 * sin(p1);
    a2 = r2 * cos(p2);
    b2 = r2 * sin(p2);
    ans1 = a1 * a2 - b1 * b2;
    ans2 = a1 * b2 + b1 * a2;
    if(fabs(ans1) < 0.01) {
        ans1 = 0.0f;
    }
    if(fabs(ans2) < 0.01) {
        ans2 = 0.0f;
    }

    if(ans2 < 0) {
        printf("%.2lf-%.2lfi", ans1, fabs(ans2));
    }
    else {
        printf("%.2lf+%.2lfi", ans1, ans2);
    }

    return 0;
}

