// PAT B1084

/*
用string数组存储每次输出的字符串
每次循环时，检测上一个字符串每个字符。
1 如果是首个字符，则存入tempStr并置子计数变量subCount为1
2 如果非首个字符，又有2种情形
	2-1 和上一个字符相同，子计数变量继续计数
	2-2 和上一个字符不同，则中止计数
		将上个字符计数subCount存入tempStr 
		将当前字符存入tempStr
		重置subCount为1（勿忘！因为忘却，第一版出错） 
*/ 

#include <cstdio>
#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int d, n;
    cin >> d >> n;
    vector<string> output(n + 1);   // store output series
    output[1] += char(d + '0');
    for(int i = 2; i <= n; i++) {
        string tempStr;
        int subCount;
        for(int j = 0; output[i-1][j] != '\0'; j++) {
            if(j == 0) {
            // if it is the first digit of the output string
                tempStr += output[i-1][j];
                subCount = 1;
            }
            else {
                if(output[i-1][j] == output[i-1][j-1]) {
                // if current digit is same as the last one
                    subCount++;
                }
                else {
                // if current digit is different from the last one
                    // add last digit's count to the output string
                    tempStr += char(subCount + '0');
                    // add current digit to the output string
                    tempStr += output[i-1][j];
                    // reset subCount
                    subCount = 1;
                }
            }
        }
        // add count of the last digit to the end of the output string
        tempStr += char(subCount + '0');
        // output string finished, add to the list
        output[i] = tempStr;
    }
    cout << output[n];

    return 0;
}


