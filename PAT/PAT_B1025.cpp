// PAT B1025

/*
�������ݺ󣬸���next�����н���ַ����
�����п�����������Ϊ������㣡�����Ҫ����sum��������������Ч����
���Ա����õ�����Ϊ��0��sum - sum%k�� β������k���Ĳ��������á�

����ʹ��reverse(begin(sum) + i, begin(sum) + i + k);
ע�⣡ȡsum������ͷʹ��:begin(sum)������reverse����

�����������ú��sorted����
*/

#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int first, nodeNum, k, tempAdd;
    int data[100005], next[100005], linkedList[100005];
    // data input
    cin >> first >> nodeNum >> k;
    for(int i = 0; i < nodeNum; i++) {
        cin >> tempAdd;
        cin >> data[tempAdd] >> next[tempAdd];
    }
    // reverse the list
    int listLen = 0;
    while(first != -1) {
        linkedList[listLen++] = first;
        first = next[first];
    }
    for(int i = 0; i < listLen - listLen % k; i += k) {
        reverse(begin(linkedList) + i, begin(linkedList) + i + k);
    }
    // print result
    for(int i = 0; i < listLen - 1; i++) {
        printf("%05d %d %05d\n", linkedList[i], data[linkedList[i]], linkedList[i + 1]);
    }
    printf("%05d %d -1", linkedList[listLen - 1], data[linkedList[listLen - 1]]);

    return 0;
}

