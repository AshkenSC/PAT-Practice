// PAT B1025

/*
输入数据后，根据next将所有结点地址排序。
排序中可能有输入结点为孤立结点！因此需要变量sum单独计算链表有效长度
可以被逆置的链表为从0到sum - sum%k， 尾部不足k个的不参与逆置。

逆置使用reverse(begin(sum) + i, begin(sum) + i + k);
注意！取sum的数组头使用:begin(sum)，否则reverse报错。

最后按序输出逆置后的sorted数组
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

