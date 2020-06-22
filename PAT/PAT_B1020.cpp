// PAT B1020

/*

�ȼ��㵥�ۣ������۽��������±���Ȼ������±�������ʣ�����������Ƚϡ�
�����ǰ����±�������ʣ���������ȫ��ʣ��������ǰ����±��������ܼۣ��˳�ѭ���� 
�����ǰʣ������ȵ�ǰ����±�������ǰȫ������±� ��������һ�֡� 

ע�⣺�����ܼ۵�forѭ�� ������������ maxNeed > 0 && i < num��
����ͬʱ����i < num���������±������ң�������û����������
������Ե�3���δ��� 

Use sort() to sort a custom structure vector:
sort(mooncakes.begin(), mooncakes.end(), cmp);

*/

#include <cstdio>
#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Mooncake {
    double storage;
    double totalPrice;
    double unitPrice;
};

bool cmp(Mooncake a, Mooncake b);

int main() {
    // data input
    int num;
    double maxNeed;
    cin >> num >> maxNeed;
    vector<Mooncake> mooncakes(num);
    for(int i = 0; i < num; i++) {
        cin >> mooncakes[i].storage;
    }
    for(int i = 0; i < num; i++) {
        cin >> mooncakes[i].totalPrice;
        mooncakes[i].unitPrice = mooncakes[i].totalPrice / mooncakes[i].storage;
    }
    sort(mooncakes.begin(), mooncakes.end(), cmp);

    // calculate profit
    double totalProfit = 0.0;
    for(int i = 0; maxNeed > 0 && i < num; i++) {
        if(maxNeed < mooncakes[i].storage) {
            totalProfit += maxNeed * mooncakes[i].unitPrice;
            break;
        }
        else {
            totalProfit += mooncakes[i].totalPrice;
            maxNeed -= mooncakes[i].storage;
        }
    }

    // print result
    printf("%.2lf", totalProfit);

    return 0;
}

bool cmp(Mooncake a, Mooncake b) {
    return a.unitPrice > b.unitPrice;
}


