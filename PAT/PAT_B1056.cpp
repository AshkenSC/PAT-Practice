// PAT B1056

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

int main() {

    int sum = 0;
    int num;
    int input[10];

    scanf("%d", &num);
    for(int i = 0; i < num; i++) {
        scanf("%d", &input[i]);
    }

    for(int i = 0; i < num; i++) {
        for(int j = 0; j < num; j++) {
            if(i == j) continue;
            else {
                sum += input[i] * 10 + input[j];
            }
        }
    }

    printf("%d", sum);

    return 0;
}

