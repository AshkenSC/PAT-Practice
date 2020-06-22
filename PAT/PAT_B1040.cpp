// PAT B1040

/*
以A为pivot，将每个A左边P的数量乘以其右边T的数量，就是当前A能组成的PAT数量

首先遍历记录T个数； 
再遍历计算PAT数量。遇到P，则P计数++；遇到T则T计数==；
遇到A，则按上述计算当前A能组成的PAT数量。

最后记得 对 1000000007 取余数。 
*/

#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

int main() {
    string input;
    int pCount = 0, tCount = 0;
    long long patCount = 0;

    getline(cin, input);
    int len = input.size();
    for(int i = 0; i < len; i++) {
        if(input[i] == 'T') {
            tCount++;
        }
    }
    for(int i = 0; i < len; i++) {
        if(input[i] == 'P') {
            pCount++;
        }
        if(input[i] == 'T') {
            tCount--;
        }
        if(input[i] == 'A') {
            patCount += pCount * tCount;
        }
    }

    patCount %= 1000000007;
    cout << patCount;
    return 0;
}

