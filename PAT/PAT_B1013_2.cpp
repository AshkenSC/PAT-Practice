// PAT B1013

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// �ж�a�Ƿ�Ϊ����
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
    
    // �ҵ�PM,PN֮�������������������primes��
    while(primeCount < N) {
        if(isPrime(number) == true) {
            printCount++;
            if(primeCount >= M)
                primes.push_back(number);
        }
        number++;
    }

    // ����ʽ������з���Ҫ���������ע�����ĩλ��Ҫ�пո�
    // ���ⷨ���������ÿ�е�һ��������������ո�+����
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