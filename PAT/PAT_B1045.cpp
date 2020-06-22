// PAT B1045

/*
防止超时的核心判断规则：1) 在正确排序的位置上; 2) 大于左侧所有数

第一点利用了快排的性质：经过一趟后pivot一定在其正确位置上。
第二点避免了判断右侧，减少了比较次数。但我还没能从理论上理解其正确性。

注意：对于pivot为0个的情况，除输出0外，还需要输出一个空换行！ 
*/

#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int num;
    cin >> num;
    vector<long long> a(num), b(num);
    vector<int> pivots;
    for(int i = 0; i < num; i++) {
        cin >> a[i];
        b[i] = a[i];
    }

    sort(b.begin(), b.begin() + num);
    long long maxNum = -1;
    for(int i = 0; i < num; i++) {
        if(a[i] == b[i] && a[i] > maxNum) {
        // KEY! You only have to ensure that a[i] > max on the left
        // no need to judge if a[i] < min on the right
            pivots.push_back(a[i]);
        }
        if(a[i] > maxNum) {
            maxNum = a[i];
        }
    }

    sort(pivots.begin(), pivots.begin() + pivots.size());
    cout << pivots.size() << endl;
    for(int i = 0; i < pivots.size(); i++) {
        if(i != 0) {
            cout << " ";
        }
        cout << pivots[i];
    }
    if(pivots.size() == 0) {
    // You have to print an EMPTY line when there is no pivot
        printf("\n");
    }

    return 0;
}

