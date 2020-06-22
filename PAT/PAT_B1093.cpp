// PAT B1093

/*
问题：怎样接收输入的两个句子。如果用string则无法收到空格后的内容。
解答：应该使用getline(cin, string s)
*/

#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

int main() {
    string a, b, sum;

    int appeared[200] = {0};
    getline(cin, a);
    getline(cin, b);
    sum = a + b;

    for(int i = 0; i < sum.size(); i++) {
        if(appeared[sum[i]] == 0) {
            printf("%c", sum[i]);
            appeared[sum[i]] = 1;
        }
    }

    return 0;
}