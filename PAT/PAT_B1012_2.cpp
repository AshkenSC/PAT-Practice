// PAT B1012

/*
每个输入的数字按照除以5余数的不同，分别存放在不同vector中；
完成输入后，根据题目要求，分别进行A1到A5的计算；
最后输出结果，注意按照题目格式要求输出，例如N以及末位的空格等。
*/

#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n, input;
    int A1 = 0, A2 = 0, A5 = 0;
    double A4 = 0.0;
    vector<int> classified[5];
    cin >> n;

    // 根据输入数input余数不同，放在不同vector里
    for (int i = 0; i < n; i++) {
        cin >> input;
        classified[input % 5].push_back(input);
    }

    // 根据题目要求进行计算
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < classified[i].size(); j++) {
            // 计算A1
            if (i == 0 && classified[i][j] % 2 == 0)
                A1 += classified[i][j];
            // 计算A2，余数为0则加，余数为1则减
            if (i == 1 && j % 2 == 0)
                A2 += classified[i][j];
            if (i == 1 && j % 2 == 1)
                A2 -= classified[i][j];
            // 计算A4之前，先求出被5除余3的数之和
            if (i == 3)
                A4 += classified[i][j];
            // 求A5，找出被5除余4的最大者
            if (i == 4 && classified[i][j] > A5)
                A5 = classified[i][j];
        }
    }

    // 输出结果
    for (int i = 0; i < 5; i++) {
        // 空格控制
        if (i != 0)
            printf(" ");
        // 当不存在符合条件的数时输出N
        if (i == 0 && A1 == 0 || i != 0 && classified[i].size() == 0) {
            printf("N");
            continue;
        }
        // 输出A1到A5
        if (i == 0)
            printf("%d", A1);
        if (i == 1)
            printf("%d", A2);
        if (i == 2)
            printf("%d", classified[2].size());
        if (i == 3)
            printf("%.1f", A4 / classified[3].size());
        if (i == 4)
            printf("%d", A5);
    }
    return 0;
}
