// PAT B1084

/*
��string����洢ÿ��������ַ���
ÿ��ѭ��ʱ�������һ���ַ���ÿ���ַ���
1 ������׸��ַ��������tempStr�����Ӽ�������subCountΪ1
2 ������׸��ַ�������2������
	2-1 ����һ���ַ���ͬ���Ӽ���������������
	2-2 ����һ���ַ���ͬ������ֹ����
		���ϸ��ַ�����subCount����tempStr 
		����ǰ�ַ�����tempStr
		����subCountΪ1����������Ϊ��ȴ����һ����� 
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


