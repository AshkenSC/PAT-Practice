/*
��1���������ÿһ�����֣�����3n+1������֤��������isVerified��¼��֤����������֤�������������ж�Ӧλ��Ϊ1��������3����֤������isVerified[3] == 1��
��2��������������֣�ʹ��sort()�����Ӵ�С����
��ע������sort()������ʹ�÷������������������������cmp()������ʹ�÷�����
��3���������isVerified[]��ӦλΪ0��������Ϊδ��֤�������֣�������Ĺؼ����֡�
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(int a, int b) {
    return a > b;
}

int main()
{
    int isVerified[5000];
    int n, k;
    bool spaceFlag = false;
    cin >> k;
    vector<int> data(k);

    for(int i = 0; i < k; i++) {
        cin >> n;
        data[i] = n;
        while(n != 1) {
            if(n % 2 == 1) {
                n = 3 * n + 1;
            }
            n = n / 2;
            if(isVerified[n] == 1) {
                break;
            }
            isVerified[n] = 1;
        }
    }

    sort(data.begin(), data.end(), cmp);

    for(int i = 0; i < data.size(); i++) {
        if(isVerified[data[i]] == 0) {
        // δ����֤�����ǹؼ�����
            if(spaceFlag == true) {
                cout << " ";
            }
            cout << data[i];
            spaceFlag = true;
        }
    }

    return 0;
}
