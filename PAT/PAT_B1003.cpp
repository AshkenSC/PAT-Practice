// PAT B1003

/*
1. �ؼ����������3���京���ǣ�����P֮ǰ��a��A��
��PT֮��ÿ��һ��A����T�����Ҫ��a��A��
�����ǣ�PǰA����*PT֮��A����==T��A����

2. ʹ��map�洢���ֹ�����ĸ������ִ�����

3. ע���ַ�������ϸ��Ҫ��
���ҽ���PAT������ĸ��
PT���ҽ���һ����
PT֮�䲻����A��ĸ��
������������3
*/

#include <iostream>
#include <map>
using namespace std;

int main()
{
    int num;
    cin >> num;
    int pPos = 0, tPos = 0;
    string s;

    for(int i = 0; i < num; i++)
    {
        cin >> s;
        //map charCountͳ�Ƹ���ĸ��������
        map<char, int> charCount;
        // �����ַ�����ͳ���ַ�������λ��
        for(int j = 0; j < s.length(); j++)
        {
            charCount[s[j]]++;
            // ��¼P��T λ��
            if(s[j] == 'P')
                pPos = j;
            if(s[j] == 'T')
                tPos = j;
        }
        // ����ַ����Ƿ����Ҫ��
        if(charCount['P']==1 && charCount['T']==1 &&
                charCount['A'] != 0 &&
                charCount.size() == 3 &&
                tPos - pPos != 1 &&
                // P��*PT֮�� == T�ң�
                pPos*(tPos - pPos - 1) == s.length() - tPos - 1)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}