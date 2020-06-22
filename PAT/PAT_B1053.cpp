// PAT B1053

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

int main() {

    int n, d; double e;
    int maybeEmpty = 0, reallyEmpty = 0;
    int observeDay, lowDay; double power;

    scanf("%d %lf %d", &n, &e, &d);
    for(int i = 0; i < n; i++) {
        scanf("%d", &observeDay);
        lowDay = 0;
        for(int j = 0; j < observeDay; j++) {
            scanf("%lf", &power);
            if(power < e) {
                lowDay++;
            }
        }
        if(lowDay > (observeDay / 2)) {
            if(observeDay > d) {
                reallyEmpty++;
            }
            else {
                maybeEmpty++;
            }
        }
    }

    printf("%.1lf%% %.1lf%%", 100 * (double)maybeEmpty / (double)n, 100 * (double)reallyEmpty / (double)n);

    return 0;
}

