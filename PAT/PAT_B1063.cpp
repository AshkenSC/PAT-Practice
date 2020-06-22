// PAT B1063

#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
#include <cmath>

using namespace std;

int main() {

    long num, real, imaginary;
    long square = 0;

    scanf("%ld", &num);
    for(long i = 0; i < num; i++) {
        scanf("%ld %ld", &real, &imaginary);
        if(real * real + imaginary * imaginary > square) {
            square = real * real + imaginary * imaginary;
        }
    }
    printf("%.2lf", sqrt(square));

    return 0;
}

