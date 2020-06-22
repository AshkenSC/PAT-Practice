// PAT B1002

/*
����˼·����������������ܺܳ�����˽�����Ϊ�ַ����洢������
�����ַ���������ASCII���ȥ'0'��ASCII��ɵ�ÿһλ����ֵ���Ӷ�ʵ����ͣ�
�����ɺ󣬽��͵���ֵҲת��Ϊ�ַ��������ڰ�λ���ƴ����
�����͵��ַ�����ÿ����һλ���ͽ���ASCII��ȥ'0'�õ���ֵ���Ӷ���ǡ����Ϊƴ���洢������±ꡣ

ע�⣺Ҫ��������ĩλ�����пո�
*/

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string hanzi[10] = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};

/*
��������ת�ַ����������ڲ�֧��C++11�Ļ���ʹ��
��Ҫ#include <algorithm>

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
    string input;		// �洢�������
    cin >> input;
    int sum = 0;		// ��¼��λ��֮��

    // �����������
    for(int i = 0; i < input.length(); i++)
        sum += input[i] - '0';
    // ��sumת��Ϊ�ַ���
    string output = to_string(sum);
    // �����͵��ַ���output��ת��Ϊƴ��
    for(int i = 0; i < output.length(); i++)
    {
        if( i != 0)
            cout << " ";
        cout << hanzi[output[i]-'0'];
    }
    return 0;
}
