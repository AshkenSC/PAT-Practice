// PAT B1012

/*
ÿ����������ְ��ճ���5�����Ĳ�ͬ���ֱ����ڲ�ͬvector�У�
�������󣬸�����ĿҪ�󣬷ֱ����A1��A5�ļ��㣻
�����������ע�ⰴ����Ŀ��ʽҪ�����������N�Լ�ĩλ�Ŀո�ȡ�
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

    // ����������input������ͬ�����ڲ�ͬvector��
    for (int i = 0; i < n; i++) {
        cin >> input;
        classified[input % 5].push_back(input);
    }

    // ������ĿҪ����м���
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < classified[i].size(); j++) {
            // ����A1
            if (i == 0 && classified[i][j] % 2 == 0)
                A1 += classified[i][j];
            // ����A2������Ϊ0��ӣ�����Ϊ1���
            if (i == 1 && j % 2 == 0)
                A2 += classified[i][j];
            if (i == 1 && j % 2 == 1)
                A2 -= classified[i][j];
            // ����A4֮ǰ���������5����3����֮��
            if (i == 3)
                A4 += classified[i][j];
            // ��A5���ҳ���5����4�������
            if (i == 4 && classified[i][j] > A5)
                A5 = classified[i][j];
        }
    }

    // ������
    for (int i = 0; i < 5; i++) {
        // �ո����
        if (i != 0)
            printf(" ");
        // �������ڷ�����������ʱ���N
        if (i == 0 && A1 == 0 || i != 0 && classified[i].size() == 0) {
            printf("N");
            continue;
        }
        // ���A1��A5
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
