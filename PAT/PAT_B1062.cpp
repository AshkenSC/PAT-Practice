// PAT B1062

#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
#include <cmath>

using namespace std;

bool IsPrime(long a, long b);

int main() {

    long n1, m1, n2, m2, k;
    long numerator1, numerator2;

    scanf("%ld/%ld %ld/%ld %ld", &n1, &m1, &n2, &m2, &k);
    numerator1 = n1 * m2 * k;
    numerator2 = n2 * m1 * k;
    if(numerator1 > numerator2) {
        swap(numerator1, numerator2);
    }

    long j = 1;
    long i = j * m1 * m2;
    bool isFirst = true;
    // locate the first possible output number
    while(i <= numerator1) {
        i += m1 * m2;
        j++;
    }
    // print result
    for(; i < numerator2; j++) {
        if(IsPrime(j, k) == true && isFirst == true) {
            printf("%ld/%ld", j, k);
            isFirst = false;
        }
        // if it is not the first-printed number, print a space 
        else if(IsPrime(j, k) == true && isFirst == false) {
            printf(" %ld/%ld", j, k);
        }
        i += m1 * m2;
    }

    return 0;
}

bool IsPrime(long a, long b) {
    long c;
    if(a < b) {
        swap(a, b);
    }
    while(1) {
        if(a % b == 0) {
            if(b == 1)
                return true;
            else
                return false;
        }
        else {
            c = a % b;
            a = b;
            b = c;
        }
    }
}

