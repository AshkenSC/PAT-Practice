// PAT A1001

/*
1. ����ֵת��Ϊ�ַ�����to_string(num)������string
2. ���Ų��Ǵ�ͷ��ÿ��λһ�������Ǵ�β��ÿ��λһ��


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
