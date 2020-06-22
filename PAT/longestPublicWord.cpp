// ���ϴ�ѧC++����
// �����ַ��������������

/*

�ַ����������
��1��strtok(�ַ������ָ��־�ַ�)
��2��char*��ֱ�Ӵ���string��string��Ϊchar*��Ҫ��c_str()����

���ϲ������
��1��set.insert()����Ԫ��
��2��set<datatype>::iterator it������������

*/

#include <cstdio>
#include <iostream>
#include <set>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

int main() {

    char s1[] = "hello this is aaaaaa bbbbbbb";
    char s2[] = "hello i am aaaaaaa bbbbbbb";
    const char *divide = " ";
    char *p;
    set<string> words1, words2, common;

    // ��S1���ʼ���
    p = strtok(s1, divide);
    while(p) {
        string tmp = p;
        words1.insert(tmp);
        p = strtok(nullptr, divide);
    }

    // ��S2���ʼ���
    p = strtok(s2, divide);
    while(p) {
        string tmp = p;
        words2.insert(tmp);
        p = strtok(nullptr, divide);
    }

    // ��S1 S2�������������ʼ��ϣ�
    set_intersection(words1.begin(), words1.end(), words2.begin(), words2.end(), inserter(common, common.end()));

    // �ҵ�����󳤶�
    int maxLen = -1;
    for(set<string>::iterator it = common.begin(); it != common.end(); it++) {
        if((int)(*it).length() > maxLen) {
            maxLen = (*it).length();
        }
    }

    // �����󳤶ȵ���
    for(set<string>::iterator it = common.begin(); it != common.end(); it++) {
        if((*it).size() == maxLen) {
            cout << *it << " ";
        }
    }

    return 0;
}
