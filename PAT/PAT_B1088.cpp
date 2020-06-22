// PAT B1088

/*
    (jia % 10) * 10 + (jia / 10) = yi
    abs(jia - yi) / X = bing;
    yi = Y * bing;
    
    ���������������̣���99��10������
	ǰ�������и�ֵ�������������жϹ�ϵ�Ƿ��������
	ע�⣡�������ܷ������������Ҫ��double������ʱ
		bing = (double)(abs(jia - yi)) / (double)x;
	ҲҪע������ת��������ò������� 
*/

#include <cstdio>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int me, x, y;
    int jia, yi;
    double bing;

    cin >> me >> x >> y;
    for(jia = 99; jia >= 10; jia--) {
        yi = jia / 10 + jia % 10 * 10;
        bing = (double)(abs(jia - yi)) / (double)x;
        if(yi == y * bing) {
            break;
        }
    }

    if(jia == 9) {
        cout << "No Solution";
    }
    else {
        cout << jia << " ";
        double threesome[3] = {jia, yi, bing};
        for(int i = 0; i < 3; i++) {
            if(threesome[i] > me) {
                cout << "Cong";
            }
            else if(threesome[i] == me) {
                cout << "Ping";
            }
            else {
                cout << "Gai";
            }
            if(i != 2) {
                cout << " ";
            }
        }
    }

    return 0;
}


