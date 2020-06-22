// PAT B1006 解法一

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

int main()
{
    int input, temp;
    scanf("%d", &input);
    for(;input != 0;)
    {
        if(input >= 100)
        {
            for(int i = 0; i < input/100; i++)
            {
                printf("B");
            }
            input = input % 100;
        }
        if(input >= 10 && input < 100)
        {
            for(int i = 0; i < input/10; i++)
            {
                printf("S");
            }
            input = input % 10;
        }
        if(input < 10)
        {
            for(int i = 1; i <= input; i++)
            {
                printf("%d", i);
            }
            input = input / 10;
        }
    }

    return 0;
}

/*
// PAT B1006 解法二

/*
由题设知，测试样例不超过三位数，因此可根据一位数、两位数、三位数分三种情况讨论
将输入的数值作为字符串存储 根据字符串长度判断位数
*/

#include <iostream>
using namespace std;

int main()
{
    string input;
    cin >> input;

    if(input.length() == 1) {
        for(int i = 0; i < input[0] - '0'; i++) {
            cout << i + 1;
        }
    }
    else if(input.length() == 2) {
        for(int i = 0; i < input[0] - '0'; i++) {
            cout << "S";
        }
        for(int i = 0; i < input[1] - '0'; i++) {
            cout << i + 1;
        }
    }
    else {
        for(int i = 0; i < input[0] - '0'; i++) {
            cout << "B";
        }
        for(int i = 0; i < input[1] - '0'; i++) {
            cout << "S";
        }
        for(int i = 0; i < input[2] - '0'; i++) {
            cout << i + 1;
        }
    }

    return 0;
}

*/

/*
// PAT B1006 解法三

/*
将输入数据作为整数存储，并用求余数法得到各位数值，将各位数值存于数组digit[3]中
注意：digit[3]应初始化为全0，以确保输入数据为两位数和一位数时，digit[3]多余空出的位为0，使输出结果正确
根据digit[3]各位数，按题目要求输出即可
*/

#include <iostream>
using namespace std;

int main()
{
    int input;
    int digit[3] = {0};     // 依次存放个、十、百位

    cin >> input;
    for(int i = 0; input > 0; input = input / 10) {
        digit[i++] = input % 10;
    }

    for(int i = 0; i < digit[2]; i++) {
        cout << "B";
    }
    for(int i = 0; i < digit[1]; i++) {
        cout << "S";
    }
    for(int i = 0; i < digit[0]; i++) {
        cout << i + 1;
    }

    return 0;
}
*/





