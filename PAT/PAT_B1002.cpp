// PAT B1002

/*
整体思路：由于输入的数可能很长，因此将其作为字符串存储并处理；
遍历字符串，将其ASCII码减去'0'的ASCII码可得每一位的数值，从而实现求和；
求和完成后，将和的数值也转化为字符串，便于按位输出拼音；
遍历和的字符串，每经过一位，就将其ASCII减去'0'得到数值，从而又恰好作为拼音存储数组的下标。

注意：要求输出结果末位不得有空格。
*/

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string hanzi[10] = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};

/*
自制整数转字符串函数，在不支持C++11的环境使用
需要#include <algorithm>

string intToString(int num) {
    string out;
    char c;
    while(num > 0) {
        c = num % 10 + '0';
        num = num / 10;
        out += c;
    }
    reverse(out.begin(), out.end());
    return out;
}
*/

int main()
{
    string input;		// 存储输入的数
    cin >> input;
    int sum = 0;		// 记录各位数之和

    // 遍历输入的数
    for(int i = 0; i < input.length(); i++)
        sum += input[i] - '0';
    // 将sum转化为字符串
    string output = to_string(sum);
    // 遍历和的字符串output，转化为拼音
    for(int i = 0; i < output.length(); i++)
    {
        if( i != 0)
            cout << " ";
        cout << hanzi[output[i]-'0'];
    }
    return 0;
}
