// PAT B1088

/*
    (jia % 10) * 10 + (jia / 10) = yi
    abs(jia - yi) / X = bing;
    yi = Y * bing;
    
    根据上述三个方程，从99到10遍历甲
	前两个进行赋值，第三个用于判断关系是否成立即可
	注意！！丙可能非整数，因此需要用double，计算时
		bing = (double)(abs(jia - yi)) / (double)x;
	也要注意类型转换，否则得不到满分 
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


