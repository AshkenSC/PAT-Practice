/*
（1）对输入的每一个数字，进行3n+1猜想验证。用数组isVerified记录验证过的数，验证过的数在数组中对应位设为1。例如若3被验证过，则isVerified[3] == 1；
（2）随后对输入的数字，使用sort()函数从大到小排序；
（注意掌握sort()函数的使用方法，尤其是其第三个参数，cmp()函数的使用方法）
（3）输出所有isVerified[]对应位为0的数，即为未验证过的数字，即待求的关键数字。
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(int a, int b) {
    return a > b;
}

int main()
{
    int isVerified[5000];
    int n, k;
    bool spaceFlag = false;
    cin >> k;
    vector<int> data(k);

    for(int i = 0; i < k; i++) {
        cin >> n;
        data[i] = n;
        while(n != 1) {
            if(n % 2 == 1) {
                n = 3 * n + 1;
            }
            n = n / 2;
            if(isVerified[n] == 1) {
                break;
            }
            isVerified[n] = 1;
        }
    }

    sort(data.begin(), data.end(), cmp);

    for(int i = 0; i < data.size(); i++) {
        if(isVerified[data[i]] == 0) {
        // 未被验证过，是关键数字
            if(spaceFlag == true) {
                cout << " ";
            }
            cout << data[i];
            spaceFlag = true;
        }
    }

    return 0;
}
