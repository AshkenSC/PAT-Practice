// PAT B1008

/*
就地循环右移M位可分为三步进行：
（1）逆置整个数组；
（2）逆置前M位；
（3）逆置余下位。

reverse函数的两个参数分别为：
（1）被逆置的范围起点；
（2）（注意）被逆置的范围终点的后一位；
（可简单记作“左闭右开”。类似sort函数的范围）
*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];
    // 注意！m有可能大于n，此时相当于循环右移m % n位
    // 为处理此情形，需要m = m % n
    m = m % n;
    if(m != 0) {
        // 注意reverse的第二个参数，为被逆置的末位元素的后一位
        reverse(a.begin(), a.begin() + n);
        reverse(a.begin(), a.begin() + m);
        reverse(a.begin() + m, a.begin() + n);
    }
    for(int i = 0; i < n; i++) {
        cout << a[i];
        // 确保末尾没有空格
        if(i != n - 1) {
            cout << " ";
        }
    }
    return 0;
}


