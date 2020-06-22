// PAT B1007

/*
��5��n���ж����2���������Ƿ�ͬʱΪ�����������㣬�������Ը���+1��

�ж�����ʱ�����ϸ��ն����жϣ���ᳬʱ���ж�m�Ƿ�Ϊ������ֻ���2�жϵ�����m�����Ƿ����������ɡ�
��Ϊ��m�Ǻ��������������Ϊ���������Ļ�������һ����С�ڵ��ڸ���m������һ����Ȼ���ڵ��ڸ���m��
��ˣ�����С�ڵ��ڸ���m�ķ�Χ�ڷ���m�����������Ȼ����һ����Ӧ�ġ����ڵ��ڸ���m�������������˻�Ϊm��
����ֻ���жϸ���m��Χ���Ƿ����������Ϳ�ȷ��m�Ƿ�Ϊ������
*/

#include <iostream>
#include <cmath>
using namespace std;

// �ж�����
bool isPrime(int num) {
    for (int i = 2; i <= sqrt(num); i++)
        if (num % i == 0)
            return false;
    return true;
}

int main() {
    int n;
    int primeCnt = 0;
    cin >> n;
    for (int i = 5; i <= n; i++)
        if (isPrime(i-2) && isPrime(i))
            primeCnt++;
    cout << primeCnt;
    return 0;
}