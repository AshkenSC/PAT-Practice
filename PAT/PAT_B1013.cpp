// PAT B1013

#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

int main() {
    int m, n;
    int primeCount = 0;
    int lineControl = 0; // control line change
    bool isPrime = true;

    // threshold input
    scanf("%d %d", &m, &n);
    // calculate prime numbers
    for(int number = 2; n > 0; number++) {
        // reset prime number flag
        isPrime = true;
        // judge if current number is prime
        for(int i = 2; i <= sqrt(number); i++) {
            if(number % i == 0) {
                isPrime = false;
            }
        }
        if(isPrime == true) {
            primeCount++;
            n--;
            // start printing from number m prime number
            if(primeCount >= m) {
                printf("%d", number);
                lineControl++;
                // format control
                if(n >= 1) {
                    if(lineControl % 10 == 0) {
                        printf("\n");
                    }
                    else {
                        printf(" ");
                    }
                }
            }
        }
    }

    return 0;
}





