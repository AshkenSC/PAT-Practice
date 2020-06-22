// PAT B1013

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// 判断a是否为素数
bool isPrime(int a) {
    for (int i = 2; i <= sqrt(a); i++)
        if(a % i == 0)
            return false;
    return true;
}

int main() {
    int M, N;
    int number = 2, primeCount = 0;
    vector<int> primes;
    
    cin >> M >> N;
    
    // 找到PM,PN之间的所有素数，并存入primes中
    while(primeCount < N) {
        if(isPrime(number) == true) {
            printCount++;
            if(primeCount >= M)
                primes.push_back(number);
        }
        number++;
    }

    // 按格式输出所有符合要求的素数，注意控制末位不要有空格
    // 本解法采用先输出每行第一个数，再输出“空格+数”
    primeCount = 0;
    for(int i = 0; i < primes.size(); i++)
    {
        primeCount++;
        if(primeCount % 10 != 1) {
            cout << " ";
        }
        cout << primes[i];
        if(primeCount % 10 == 0) {
            cout << endl;
        }
    }

    return 0;
}