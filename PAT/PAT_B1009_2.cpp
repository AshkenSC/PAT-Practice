// PAT B1009

/*
ʹ��stack��ջ���洢���ʡ�����stack���С��Ƚ�����������ԣ������������ĵ��ʽ������������������ڱ��⣻
������ʹ�õ���stack�Ļ���������
stack<��������> stackName;	����һ����ΪstackName��ָ�����͵�ջ��
stack.push(a);		��Ԫ��a��ջ��
stack.pop();		������ɾ����ջ��Ԫ�أ�
stack.top();		����ջ��Ԫ�أ�
stack.empty();		����һ������ֵ��ջ��Ϊtrue���ǿ�Ϊfalse��
*/

#include <iostream>
#include <stack>
using namespace std;

int main()
{
    stack<string> words;
    string input;
    while(cin >> input) {
        words.push(input);
    }
    while(!words.empty())
    {
        cout << words.top();
        words.pop();
        if(!words.empty()) {
        // ����ĩβ�ո�
            cout << " ";
        }
    }
    return 0;
}


