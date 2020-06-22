// PAT B1092

/*
���⣺ �Զ������͵�vector����ֱ���±긳ֵ���ᵼ��segment fault

���ö�ά����[m][n]�洢���ݣ�����[n]�洢�ͣ�
����[n]���ñ���maxSell�洢�������

Ϊ���ƿո������spaceCntr��ÿ�����һ����ž�+1��
��������spaceCntr��0ʱ��������ո�

*/

#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#define N 1010
#define M 110

using namespace std;

struct CakeInfo {
    int serial;
    long long sum;
};

int main() {
    int data[M][N] = {0};
    int sum[N] = {0};
    int m, n;
    int maxSell = -1;

    // data input
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            cin >> data[i][j];
        }
    }

    // calculate sum
    for(int j = 0; j < n; j++) {
        for(int i = 0; i < m; i++) {
            sum[j] += data[i][j];
        }
    }

    // find max
    for(int i = 0; i < n; i++) {
        if(sum[i] > maxSell) {
            maxSell = sum[i];
        }
    }
    cout << maxSell << endl;
    int spaceCntr = 0;
    for(int i = 0; i < n; i++) {
        if(sum[i] == maxSell && spaceCntr == 0) {
            cout << i + 1;
            spaceCntr++;
        }
        else if(sum[i] == maxSell && spaceCntr != 0) {
            cout << " " << i + 1;
            spaceCntr++;
        }
    }

    return 0;
}
