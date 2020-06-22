// PAT B1065

/*
思想：有n对情侣，设置一个n行2列数组，记录情侣。k个客人用集合存储。
遍历情侣数组，当一对情侣同时在集合内时，则在客人集合中删除这对情侣
最后，切记格式化输出！否则如00000等会错误输出，无法通过4号点 
 

STL set 相关操作：
插入集合：setName.insert(data); 
删除集合中元素：setName.erase(data);
遍历集合：for(set<int>::iterator it = setName.begin(); it != setName.end(); it++);
判断元素在集合内：guest.count(coupleId[i][0]) == 1 （计数值为0） 
 
*/

#include <cmath>
#include <vector>
#include <set>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    // data input
    long numCoupled;
    cin >> numCoupled;
    vector< vector<long> > coupleId(numCoupled, vector<long>(2));
    for(long i = 0; i < numCoupled; i++) {
        cin >> coupleId[i][0] >> coupleId[i][1];
    }
    // judge if a guest is single
    long numGuest, tempGuest;
    cin >> numGuest;
    set<long> guest;
    for(long i = 0; i < numGuest; i++) {
        cin >> tempGuest;
        guest.insert(tempGuest);
    }
    for(long i = 0; i < numCoupled; i++) {
        if(guest.count(coupleId[i][0]) == 1 && guest.count(coupleId[i][1]) == 1) {
            guest.erase(coupleId[i][0]);
            guest.erase(coupleId[i][1]);
        }
    }
    // print
    cout << guest.size() << endl;
    for(set<long>::iterator it = guest.begin(); it != guest.end(); it++) {
        if(it != guest.begin()) {
            cout << " ";
        }
        printf("%05d", *it);
    }

    return 0;
}

