// PAT B1060

#include <cmath>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool cmp(long a, long b);

int main() {
    long day;
    cin >> day;
    vector<long> miles(day + 1);
    for(long i = 1; i <= day; i++) {
        cin >> miles[i];
    }
    sort(miles.begin() + 1, miles.end(), cmp);

    long eddington;
    for(eddington = 1; miles[eddington] > eddington; eddington++);
    cout << --eddington;

    return 0;
}

bool cmp(long a, long b) {
    return a > b;
}

