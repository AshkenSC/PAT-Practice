// PAT B1070

/*
若要取得最大长度，则将长绳尽可能放在后面拼接，尽可能减少长绳对折次数 
因此在输入数据后，从小到大排序，然后按照要求计算总长即可 
*/

#include <cmath>
#include <vector>
#include <set>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	// data input
    int numRope;
    cin >> numRope;
    vector<double> rope(numRope);
    for(int i = 0; i < numRope; i++) {
        cin >> rope[i];
    }
    // calculate max rope string length
    sort(rope.begin(), rope.end());
    double maxLen = rope[0];
    for(int i = 1; i < numRope; i++) {
        maxLen = maxLen / 2 + rope[i] / 2;
    }
    // print result
    cout << (int)maxLen;

    return 0;
}

