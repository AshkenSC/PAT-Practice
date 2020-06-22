// PAT B1070

/*
��Ҫȡ����󳤶ȣ��򽫳��������ܷ��ں���ƴ�ӣ������ܼ��ٳ������۴��� 
������������ݺ󣬴�С��������Ȼ����Ҫ������ܳ����� 
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

