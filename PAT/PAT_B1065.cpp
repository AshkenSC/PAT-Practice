// PAT B1065

/*
˼�룺��n�����£�����һ��n��2�����飬��¼���¡�k�������ü��ϴ洢��
�����������飬��һ������ͬʱ�ڼ�����ʱ�����ڿ��˼�����ɾ���������
����мǸ�ʽ�������������00000�Ȼ����������޷�ͨ��4�ŵ� 
 

STL set ��ز�����
���뼯�ϣ�setName.insert(data); 
ɾ��������Ԫ�أ�setName.erase(data);
�������ϣ�for(set<int>::iterator it = setName.begin(); it != setName.end(); it++);
�ж�Ԫ���ڼ����ڣ�guest.count(coupleId[i][0]) == 1 ������ֵΪ0�� 
 
*/

#include <cmath>
#include <vector>
#include <set>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    // data input
    long numCoupled;
    cin >> numCoupled;
    vector< vector<long> > coupleId(numCoupled, vector<long>(2));
    for(long i = 0; i < numCoupled; i++) {
        cin >> coupleId[i][0] >> coupleId[i][1];
    }
    // judge if a guest is single
    long numGuest, tempGuest;
    cin >> numGuest;
    set<long> guest;
    for(long i = 0; i < numGuest; i++) {
        cin >> tempGuest;
        guest.insert(tempGuest);
    }
    for(long i = 0; i < numCoupled; i++) {
        if(guest.count(coupleId[i][0]) == 1 && guest.count(coupleId[i][1]) == 1) {
            guest.erase(coupleId[i][0]);
            guest.erase(coupleId[i][1]);
        }
    }
    // print
    cout << guest.size() << endl;
    for(set<long>::iterator it = guest.begin(); it != guest.end(); it++) {
        if(it != guest.begin()) {
            cout << " ";
        }
        printf("%05d", *it);
    }

    return 0;
}

