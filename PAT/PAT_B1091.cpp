// PAT B1091

/*
    ������ automorphic number
    ��1������Mȷ����ѭ��������
    ��2��ÿ�δ�ѭ���У�ִ��Сѭ����n��1������9������Ƿ���������
    ��3����������K��λ����ͬ��1λ��2λ��3λ�������ֱ��������������
*/

#include <cmath>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    long long lineNum, testee, product;

    cin >> lineNum;
    while(lineNum > 0) {
        cin >> testee;
        int n;
        for(n = 1; n < 10; n++) {
            product = n * testee * testee;
            if(testee < 10) {
            // input number is one-digit
                if(product % 10 == testee) {
                    break;
                }
                else {
                    continue;
                }
            }
            else if(testee >= 10 && testee <= 99) {
            // input number is two-digit
                if(product % 100 == testee) {
                    break;
                }
                else {
                    continue;
                }
            }
            else {
            // input number is three-digit
                if(product % 1000 == testee) {
                    break;
                }
                else {
                    continue;
                }
            }
        }

        if(n < 10) {
        // current number is automorphic
            cout << n << " " << product << endl;
        }
        else {
        // current number is not automorphic
            cout << "No" << endl;
        }

        lineNum--;
    }

    return 0;
}