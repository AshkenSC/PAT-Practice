// PAT B1089

/*
ʹ��alibi�洢ÿ���˵ķ��ԣ�
ʹ������ѭ��������ң�ÿ��ѡ������Ϊ���ˣ����˼����¸���˵�����
����˵������Ϊ2����һ��һ��ʱ�Ϸ���������������
����״��������һ��ѭ������ѭ��������û�ҵ�����û�н�


���뼼�ɣ�
��γ�ʼ����ֵvector: vector<int> array(length, initValue);
���ȸ�ֵ��a = b = 1; �Ϸ���
*/

#include <cstdio>
#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int num;
    cin >> num;
    vector<int> alibi(num + 1);

    for(int i = 1; i <= num; i++) {
        cin >> alibi[i];
    }
    for(int i = 1; i <= num; i++) {
        for(int j = i + 1; j <= num; j++) {
            // create two new vectors in every loop
            // kinda waste of memory
            vector<int> liarsId;
            vector<int> role(num + 1, 1);

            role[i] = role[j] = -1;
            for(int k = 1; k <= num; k++) {
                if(alibi[k] * role[abs(alibi[k])] < 0) {
                    liarsId.push_back(k);
                }
            }
            if(liarsId.size() == 2) {
                if(role[liarsId[0]] * role[liarsId[1]] < 0) {
                    cout << i << " " << j;
                    return 0;
                }
                else {
                    continue;
                }
            }
            else {
                continue;
            }
        }
    }

    cout << "No Solution";
    return 0;
}


