// PAT B1092

/*
问题： 自定义类型的vector不能直接下标赋值，会导致segment fault

改用二维数组[m][n]存储数据，数组[n]存储和；
遍历[n]，用变量maxSell存储最大销量

为控制空格，设变量spaceCntr。每次输出一个编号就+1。
这样，在spaceCntr非0时，才输出空格。

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
