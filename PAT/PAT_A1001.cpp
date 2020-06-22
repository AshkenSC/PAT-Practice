// PAT A1001

/*
1. 将数值转化为字符串：to_string(num)，返回string
2. 逗号不是从头数每三位一个，而是从尾数每三位一个


*/

#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cmath>

using namespace std;

int main() {

    int a, b;
    string str;

    scanf("%d %d", &a, &b);
    str = to_string(a + b);

    for(int i = 0; i < str.size(); i++) {
        cout << str[i];
        if(str[i] == '-') {
            continue;
        }
        else if( (str.size() - i - 1) % 3 == 0 &&
           i != str.size()-1) {
            cout << ",";
        }
    }

    return 0;
}
