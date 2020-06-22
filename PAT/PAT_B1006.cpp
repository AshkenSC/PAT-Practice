// PAT B1006 �ⷨһ

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
// PAT B1006 �ⷨ��

/*
������֪������������������λ������˿ɸ���һλ������λ������λ���������������
���������ֵ��Ϊ�ַ����洢 �����ַ��������ж�λ��
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
// PAT B1006 �ⷨ��

/*
������������Ϊ�����洢���������������õ���λ��ֵ������λ��ֵ��������digit[3]��
ע�⣺digit[3]Ӧ��ʼ��Ϊȫ0����ȷ����������Ϊ��λ����һλ��ʱ��digit[3]����ճ���λΪ0��ʹ��������ȷ
����digit[3]��λ��������ĿҪ���������
*/

#include <iostream>
using namespace std;

int main()
{
    int input;
    int digit[3] = {0};     // ���δ�Ÿ���ʮ����λ

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





