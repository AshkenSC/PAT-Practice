// PAT B1079

// 要点：
// 1. 使用reverse(str.begin(), str.end())倒字符串
// 2. 在相加时，充分利用回文数的特点：从头相加，若进位末位再加1，最后倒置最终结果 
// 	  而不是蛮用各种方法试图直接从末位相加
// 3. string的各种用法：
//	  string += 'char' 直接在末位连接字符；
//    string可直接用 == 等比大小符号比较 

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

