// PAT B1079

// Ҫ�㣺
// 1. ʹ��reverse(str.begin(), str.end())���ַ���
// 2. �����ʱ��������û��������ص㣺��ͷ��ӣ�����λĩλ�ټ�1����������ս�� 
// 	  ���������ø��ַ�����ͼֱ�Ӵ�ĩλ���
// 3. string�ĸ����÷���
//	  string += 'char' ֱ����ĩλ�����ַ���
//    string��ֱ���� == �ȱȴ�С���űȽ� 

#include <iostream>
#include <algorithm>
using namespace std;

string Add(string a);

int main() {
    string str;
    cin >> str;
    int i;
    for(i = 0; i < 10; i++) {
        string revStr = str;
        reverse(revStr.begin(), revStr.end());
        if(revStr == str) {
            cout << str << " is a palindromic number.";
            break;
        }
        else {
            cout << str << " + " << revStr << " = " << Add(str) << endl;
            str = Add(str);
        }
    }
    if(i == 10) {
        cout << "Not found in 10 iterations.";
    }

    return 0;
}

string Add(string a) {
    string b = a;
    string ans;
    reverse(b.begin(), b.end());

    int length = a.length();
    int cFlag = 0;
    int num;
    for(int i = 0; i < length; i++) {
        num = (a[i] - '0') + (b[i] - '0') + cFlag;
        cFlag = 0;
        if(num >= 10) {
            num = num - 10;
            cFlag = 1;
        }
        ans += char(num + '0');
    }
    if(cFlag == 1) {
        ans += '1';
    }
    // for convenience, calculation starts from the higher digit
    // thanks to the structure of palindromic operands this method is accessible
    // so the final result should be reversed
    reverse(ans.begin(), ans.end());
    return ans;
}

